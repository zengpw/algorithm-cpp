//
//  leet_code_127_word_ladder.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/4/7.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef bfs_leet_code_127_word_ladder_h
#define bfs_leet_code_127_word_ladder_h

#include "util/leet_code_util.h"

using namespace std;

//
//  https://leetcode.com/problems/word-ladder/
//  题意： 一个数组中包含若干个单词，每次只替换 1 个字母，求 “数组中” 单词 A 变形为 单词 B 的最短距离
//
class Solution127
{
private:
    queue<pair<string, int>> wordQueue;                  // 每个匹配的单词，以及从 A 到该单词的 变形次数
    unordered_set<string> wordSet;
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // clear
        wordSet.clear();
        queue<pair<string, int>> empty;
        swap(wordQueue, empty);

        // 用来替代入参中的数组，实现快速删除
        copy(wordList.begin(), wordList.end(), inserter(wordSet, wordSet.end()));

        // 处理特殊情况
        if (beginWord == endWord || wordSet.count(endWord) == 0)
            return 0;

        // 初始化处理队列
        wordQueue.emplace(make_pair(beginWord, 1));

        while (!wordQueue.empty())
        {
            auto wordPair = wordQueue.front();

            if (wordPair.first == endWord)
                return wordPair.second;
            else
                bfs(wordPair);

            wordQueue.pop();
        }

        return 0;
    }

private:
    void bfs(const pair<string, int> &wordPair)
    {
        auto word = wordPair.first;

        // 遍历 word 的每一个字母，依次将其第 i 位替换为 26 个字母中的一个
        for (int i = 0; i < word.length(); ++i)
        {
            string wordNew = word;
            
            // 循环次数固定为 26 次
            for (int j = 0; j < 26; ++j)
            {
                wordNew[i] = 'a' + j;

                if (wordSet.count(wordNew) != 0)
                {
                    wordQueue.emplace(make_pair(wordNew, wordPair.second + 1));
                    wordSet.erase(wordNew);
                }
            }
        }
    }
};

#endif // bfs_leet_code_127_word_ladder_h
