//
//  leet_code_72_edit_distance.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/5/13.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef string_leet_code_72_edit_distance_h
#define string_leet_code_72_edit_distance_h

#include "util/int_util.h"
#include "util/leet_code_util.h"

using namespace std;

//
//  https://leetcode.com/problems/edit-distance/
//  题意： 字符串题型 - 最小编辑距离 ED
//
class Solution72
{
public:
    int minDistance(string word1, string word2)
    {
        int x = word2.size() + 1;
        int y = word1.size() + 1;

        // dp[][] -> 行代表源单词 word1, 列代表目标单词 word2
        // dp[i][j] -> 从 abcd 的前 j 个字符转换到 acd 的前 i 个字符所需要的操作次数
        int dp[x][y];
        memset(dp, 0, sizeof(dp));

        // 第一列 dp[0, n][0] 的值 -> 往下走 = 插入操作 -> dp[i][j] = dp[i - 1][j] + 1
        for (int i = 0; i < x; ++i)
        {
            dp[i][0] = i;
        }

        // 第一行 dp[0][0, n] 的值 -> 往右走 = 删除操作 -> dp[i][j] = dp[i][j - 1] + 1
        for (int j = 0; j < y; ++j)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i < x; ++i)
        {
            for (int j = 1; j < y; ++j)
            {
                // 因为 i, j 从 1 开始，所以此处要 -1
                // 如果 src[i] == src[j], 则 dp[i][j] = 左上值，代表操作次数不变
                // 如果 src[i] != src[j], 则 dp[i][j] = 左、上、左上 的最小值 + 1
                // 如果采用了 左上 的最小值 -> 往右下走 = 替换操作
                if (word1[j - 1] == word2[i - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
            }
        }

        return dp[x - 1][y - 1];
    }
};

#endif // string_leet_code_72_edit_distance_h
