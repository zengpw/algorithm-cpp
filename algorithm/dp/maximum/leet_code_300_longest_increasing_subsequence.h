//
//  leet_code_300_longest_increasing_subsequence.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/4.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_maximum_leet_code_300_longest_increasing_subsequence_h
#define dp_maximum_leet_code_300_longest_increasing_subsequence_h

#include "util/leet_code_util.h"

using namespace std;

//
//  https://leetcode.com/problems/longest-increasing-subsequence/
//  题意： 求最长递增子序列（不必连续），比如 {9, 2, 3, 1} -> {2, 3}, 长度为 2
//
class Solution300
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        // 如果只有一个成员，那么子序列最长为 1, 这个最小规模可以作为默认值
        vector<int> dp(nums.size(), 1);

        int result = 1;

        // 外层循环用于计算规模 n 的解
        for (int n = 0; n < nums.size(); ++n)
        {
            // 规模 n 需要和 规模 0 到 n - 1 进行比较（递推公式）
            for (int i = 0; i < n; ++i)
            {
                if (nums[n] > nums[i])
                {
                    dp[n] = max(dp[n], dp[i] + 1);
                }
            }

            result = max(result, dp[n]);
        }

        return result;
    }
};

#endif // dp_maximum_leet_code_300_longest_increasing_subsequence_h
