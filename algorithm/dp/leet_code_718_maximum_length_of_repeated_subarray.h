//
//  leet_code_718_maximum_length_of_repeated_subarray.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/5/9.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_718_maximum_length_of_repeated_subarray_h
#define dp_leet_code_718_maximum_length_of_repeated_subarray_h

#include "util/intUtil.h"
#include "util/leetCodeUtil.h"

using namespace std;

//
//  https://leetcode.com/problems/maximum-length-of-repeated-subarray/
//  题意： 求最长公共子串
//
class Solution718
{
public:
    int findLength(vector<int>& A, vector<int>& B)
    {
        int result = 0;

        int dp[A.size() + 1][B.size() + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i < A.size() + 1; ++i)
        {
            for (int j = 1; j < B.size() + 1; ++j)
            {
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = 0;

                result = max(result, dp[i][j]);
            }
        }

        return result;
    }
};

#endif // dp_leet_code_718_maximum_length_of_repeated_subarray_h
