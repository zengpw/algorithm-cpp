//
//  leet_code_5_longest_palindromic_substring.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/4/20.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_maximum_leet_code_5_longest_palindromic_substring_h
#define dp_maximum_leet_code_5_longest_palindromic_substring_h

#include "util/int_util.h"
#include "util/leet_code_util.h"

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
        int dp[s.length()][s.length()];

        // = 0 不是回文
        // = 1 长度为 1 的回文，仅限于 i == j
        // 长度为 j - i + 1 的回文
        memset(dp, 0, sizeof(dp));

        // pair<最大回文子串首地址，该子串长度>
        auto result = make_pair(0, 1);

        // dp[i][j] 依赖于 dp[i + 1][j - 1]
        // 如果 dp[i + 1][j - 1] 是回文，并且 s[i] == s[j]
        // 那么 dp[i][j] 是回文，并且回文长度 dp[i][j] = j - i + 1
        for (int j = 0; j < s.length(); ++j)
        {
            dp[j][j] = 1;

            for (int i = 0; i < j; ++i)
            {
                if (s[i] == s[j])
                {
                    if (j == i + 1)
                        dp[i][j] = 2;
                    else if (dp[i + 1][j - 1] > 0)
                        dp[i][j] = j - i + 1;
                }

                if (dp[i][j] > result.second)
                    result = make_pair(i, dp[i][j]);
            }
        }

        return s.substr(result.first, result.second);
    }
};

#endif // dp_maximum_leet_code_5_longest_palindromic_substring_h
