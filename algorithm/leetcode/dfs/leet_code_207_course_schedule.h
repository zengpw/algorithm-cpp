//
//  leet_code_207_course_schedule.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/4/18.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dfs_leet_code_207_course_schedule_h
#define dfs_leet_code_207_course_schedule_h

#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

//
//  https://leetcode.com/problems/course-schedule/
//  题意： 求所给课程是否冲突，实质为判断 有向图 是否有环
//
class Solution207
{
private:
    // 邻接表, key = 顶点, value = 邻接链表（只含后继结点）
    unordered_map<int, vector<int>> vertexMap;
    // 已访问列表，它的成员为 vertexMap.key
    unordered_set<int> visited;

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // clear
        vertexMap.clear();
        visited.clear();

        // 建立邻接表，直接使用 map<int, vector<int>>, 方便查找后继结点
        for (auto &courseVec : prerequisites)
        {
            for (std::size_t i = 1; i < courseVec.size(); ++i)
            {
                // 邻接链表（只含后继结点）
                vector<int> vertexAdjacent;

                if (vertexMap.count(courseVec[i]) > 0)
                {
                    vertexAdjacent = vertexMap[courseVec[i]];
                }

                vertexAdjacent.push_back(courseVec[0]);
                vertexMap[courseVec[i]] = vertexAdjacent;
            }
        }

        // 递归处理 每个顶点 及其 所有邻接点
        for (auto &v : vertexMap)
        {
            // 在处理一个顶点的过程中，需要构造一个临时 visited 列表
            // 在处理它的所有 后继顶点 过程中，如果 重复 出现在这个列表中，则说明出现了环
            unordered_set<int> visitedOnce;

            if (!dfs(v.first, v.second, visitedOnce))
                return false;
        }

        return true;
    }

private:
    bool dfs(int course, vector<int> &adjacentList, unordered_set<int> &visitedOnce)
    {
        // 已经处理过（所有后继结点）的顶点，不需要再处理
        if (visited.count(course) > 0)
            return true;

        // 它及它的后继顶点在单次处理过程中再次出现，则说明出现了环
        if (visitedOnce.count(course) > 0)
            return false;

        // 预先添加到 单次已处理列表，在处理其后继结点的过程中，会查看此表
        visitedOnce.emplace(course);

        // 处理它的邻接链表
        for (auto &v : adjacentList)
        {
            if (!dfs(v, vertexMap[v], visitedOnce))
                return false;
        }

        // 已处理完所有后继结点，添加到 已处理列表
        visited.emplace(course);

        return true;
    }
};

#endif // dfs_leet_code_207_course_schedule_h
