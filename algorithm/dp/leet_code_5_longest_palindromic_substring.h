//
//  leet_code_5_longest_palindromic_substring.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/4/20.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_5_longest_palindromic_substring_h
#define dp_leet_code_5_longest_palindromic_substring_h

#include "util/intUtil.h"
#include "util/leetCodeUtil.h"

using namespace std;

//
//  https://leetcode.com/problems/longest-palindromic-substring
//  题意： 最长回文子串，比如 {0, 1, 3, 2, 3, 0}, 最长回文子串为 {3, 2, 3}
//
class Solution5
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() < 2)
            return s;

        // 此题据说用 vector 会超时，改用 C 数组
        // dp[i][j], i = 子串首地址, j = 子串尾地址
        // 实际上这里只用到了一半的数组值，因为 j >= i 才有意义
        int dp[s.length()][s.length()];

        // dp[i][j] 有 3 种取值，先用最劣值进行填充
        // = 0 不是回文
        // = 1 长度为 1 的回文
        // 长度为 j - i + 1 的回文
        memset(dp, 0, sizeof(int)*s.length()*s.length());

        // pair<最大回文子串首地址，该子串长度>
        auto result = make_pair(0, 1);

        // 最优子结构: dp[i][j] 依赖于 dp[i + 1][j - 1]
        // 每次大循环，都会计算 [0 -> (j - 1)][j] 可能存在的回文串
        // 0: [0][0]
        // 1: [0][1], [1][1]
        // 2: [0][2], [1][2], [2][2]
        // 3: [0][3], [1][3], [2][3], [3][3]
        // 4: [0][4], [1][4], [2][4], [3][4], [4][4]
        // 5: [0][5], [1][5], [2][5], [3][5], [4][5], [5][5]
        for (int j = 0; j < s.length(); ++j)
        {
            // 该次循环的边界值（明显最优解）
            dp[j][j] = 1;

            // 判断 [0 -> (j - 2)][j] 是否是回文，并计算长度
            // 规模 n 依赖于 n - 1 的最优解
            for (int i = 0; i < j; ++i)
            {
                if (i < j - 1)
                {
                    if (s[i] == s[j] && dp[i + 1][j - 1] > 0)
                        dp[i][j] = j - i + 1;
                }
                else
                {
                    // [j - 1][j] 的情况也要特殊处理，不能套用递推公式
                    if (s[i] == s[j])
                        dp[i][j] = 2;
                }

                if (dp[i][j] > result.second)
                    result = make_pair(i, dp[i][j]);
            }
        }

        return s.substr(result.first, result.second);
    }
};

#endif // dp_leet_code_5_longest_palindromic_substring_h
