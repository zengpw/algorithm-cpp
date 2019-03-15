//
//  leet_code_300_longest_increasing_subsequence.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/4.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_300_longest_increasing_subsequence_h
#define dp_leet_code_300_longest_increasing_subsequence_h

#include "util/leetCodeUtil.h"

using namespace std;

//
//  https://leetcode.com/problems/longest-increasing-subsequence/
//  题意： 求一个给定序列最长的递增子序列
//
class Solution300
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.empty())
            return 0;

        // 如果 nums 只有1个成员，那么子序列最长为1
        int result = 1;

        // dp[n]: n = nums[n] 的下标, dp[n] = nums[n] 的值所能包含的最长递增子序列
        vector<int> dp(nums.size(), 1);

        // 每次大循环，都要计算出一个数字的最长递增子序列
        for (int n = 1; n < dp.size(); ++n)
        {
            // 这个数字可能依赖任何一个前面的值，所以要遍历它前面的所有数字，找到包含最长子序列的 dp[i]
            for (int i = 0; i < n; ++i)
            {
                if (nums[n] > nums[i])
                {
                    dp[n] = max(dp[n], dp[i] + 1);
                }
            }

            // 如果比已有记录更大，则暂存起来，避免再循环一次 dp[]
            result = max(result, dp[n]);
        }

        return result;
    }
};

#endif // dp_leet_code_300_longest_increasing_subsequence_h
