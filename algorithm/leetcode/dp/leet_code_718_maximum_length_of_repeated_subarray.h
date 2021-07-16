//
//  leet_code_718_maximum_length_of_repeated_subarray.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/5/9.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_718_maximum_length_of_repeated_subarray_h
#define dp_leet_code_718_maximum_length_of_repeated_subarray_h

#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

//
//  https://leetcode.com/problems/maximum-length-of-repeated-subarray/
//  题意： 求两个整数数组的最长公共子串
//
class Solution718
{
public:
    int findLength(vector<int> &A, vector<int> &B)
    {
        if (A.empty() || B.empty())
            return 0;

        int dp[A.size()][B.size()];
        memset(dp, 0, sizeof(dp));

        int result = 0;

        // dp[i][j] -> i, j 分别代表两个子串的最后一位
        for (int i = 0; i < A.size(); ++i)
        {
            for (int j = 0; j < B.size(); ++j)
            {
                if (A[i] == B[j])
                {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                }

                result = max(result, dp[i][j]);
            }
        }

        return result;
    }
};

#endif // dp_leet_code_718_maximum_length_of_repeated_subarray_h
