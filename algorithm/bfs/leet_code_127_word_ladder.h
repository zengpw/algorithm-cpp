//
//  leet_code_127_word_ladder.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/4/7.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef bfs_leet_code_127_word_ladder_h
#define bfs_leet_code_127_word_ladder_h

#include "util/leetCodeUtil.h"

using namespace std;

//
//  https://leetcode.com/problems/word-ladder/
//  题意： 每次只替换 1 个字母，求单词 A 到 B 的最短距离
//
class Solution127
{
private:
    queue<pair<string, int>> nQueue;           // pair<单词, 该单词到 A 的距离>
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        // clear
        queue<pair<string, int>> empty;
        swap(empty, nQueue);

        // unordered_set 方便查找和删除
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // 首先排除掉 2 种特殊情况
        if (beginWord == endWord || wordSet.count(endWord) == 0)
            return 0;

        // 初始化结果为 0 (找不到路径的情况)
        int result = 0;

        // 将起点入队
        nQueue.push(make_pair(beginWord, 1));

        while (!nQueue.empty())
        {
            auto word = nQueue.front();

            // 出队的是终点值，说明已经找到最短路径
            if (word.first == endWord)
            {
                result = word.second;
                break;
            }

            bfs(wordSet, word);
            nQueue.pop();
        }

        return result;
    }

private:
    void bfs(unordered_set<string>& wordSet, pair<string, int>& item)
    {
        string word = item.first;
        int level = item.second;

        // 遍历 word 的每一个字母，依次将其第 i 位替换为 26 个字母中的一个
        for (int i = 0; i < word.length(); ++i)
        {
            string srcTemp(word);

            // 不论 wordSet 有多大，循环次数固定为 26 次
            for (int j = 0; j < 26; ++j)
            {
                srcTemp[i] = 'a' + j;

                if (wordSet.count(srcTemp) > 0)
                {
                    nQueue.push(make_pair(srcTemp, level + 1));
                    wordSet.erase(srcTemp);
                }
            }
        }
    }
};

#endif // bfs_leet_code_127_word_ladder_h
