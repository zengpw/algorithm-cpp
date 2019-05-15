//
//  leet_code_72_edit_distance.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/5/13.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_72_edit_distance_h
#define dp_leet_code_72_edit_distance_h

#include "util/intUtil.h"
#include "util/leetCodeUtil.h"

using namespace std;

//
//  https://leetcode.com/problems/edit-distance/
//  题意： 字符串题型 - 最小编辑距离
//
class Solution72
{
public:
    int minDistance(string word1, string word2)
    {
        // dp[i][j] = word1.i 到 word.j 的距离
        // 需要额外增加一行和一列，代表最复杂的情况(word1, word2 是空串)
        int dp[word1.size() + 1][word2.size() + 1];
        memset(dp, 0, sizeof(dp));

        // 处理最复杂的情况（同时也是边界值）
        int x = 0, y = 0;
        // 第一行
        generate_n(&dp[0][0], word2.size() + 1, [&x] () mutable -> int {
            return x++;
        });
        // 第一列
        for (int k = 0; k <= word1.size(); ++k)
        {
            dp[k][0] = y++;
        }

        for (int i = 1; i <= word1.size(); ++i)
        {
            for (int j = 1; j <= word2.size(); ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }

        return dp[word1.size()][word2.size()];
    }
};

#endif // dp_leet_code_72_edit_distance_h
