//
//  leet_code_207_course_schedule.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/4/18.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef tree_leet_code_207_course_schedule_h
#define tree_leet_code_207_course_schedule_h

#include "util/leet_code_util.h"

using namespace std;

//
//  https://leetcode.com/problems/course-schedule/
//  题意： 求所给课程是否冲突，实质为判断 有向图 是否有环
//
class Solution207
{
private:
    unordered_map<int, vector<int>> vertexMap;          // 邻接表, key = 顶点, value = 邻接（只含后继结点）链表
    unordered_set<int> visited;                         // 已访问列表，它的成员为 vertexMap.key
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        // clear
        vertexMap.clear();
        visited.clear();

        // 建立邻接表，直接使用 map<int, vector<int>>, 方便查找后继结点
        for (auto& course : prerequisites)
        {
            // 邻接（只含后继结点）链表
            vector<int> successorList;

            if (vertexMap.count(course.second) > 0)
            {
                successorList = vertexMap[course.second];
            }

            successorList.push_back(course.first);
            vertexMap[course.second] = successorList;
        }

        // 处理 每个顶点 及其 所有邻接点，并递归处理 邻接点
        for (auto& v : vertexMap)
        {
            // 在处理一个顶点的过程中，需要构造一个临时 visited 列表
            // 在处理它的后继顶点过程中，如果 后继顶点 出现在这个列表中，则说明出现了环
            unordered_set<int> visitedOnce;
            
            if (!dfs(v.first, visitedOnce))
                return false;
        }

        return true;
    }
private:
    bool dfs(int vertex, unordered_set<int>& visitedOnce)
    {
        // 已经处理过（所有后继结点）的顶点，不需要再处理
        if (visited.count(vertex) > 0)
            return true;

        // 它及它的后继顶点在单次处理过程中再次出现，则说明出现了环
        if (visitedOnce.count(vertex) > 0)
            return false;

        // 预先添加到 单次已处理列表，在处理其后继结点的过程中，会查看此表
        visitedOnce.insert(vertex);

        // 处理它的邻接链表
        for (auto& v : vertexMap[vertex])
        {
            if (!dfs(v, visitedOnce))
                return false;
        }

        // 已处理完所有后继结点，添加到 已处理列表
        visited.insert(vertex);

        return true;
    }
};

#endif // tree_leet_code_207_course_schedule_h
