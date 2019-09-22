//
//  leet_code_300_longest_increasing_subsequence.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/4.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_300_longest_increasing_subsequence_h
#define dp_leet_code_300_longest_increasing_subsequence_h

#include "util/leet_code_util.h"

using namespace std;

//
//  https://leetcode.com/problems/longest-increasing-subsequence/
//  题意： 求一个给定序列最长的递增子序列，比如 {9, 2, 3, 1} -> {2, 3}
//
class Solution300
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.empty())
            return 0;

        // （边界值）如果 nums 只有1个成员，那么子序列最长为1
        int result = 1;

        // dp[n] = nums 序列所能包含的最长递增子序列, n = 序列长度
        vector<int> dp(nums.size(), 1);

        // 每次大循环，都要计算出一个 长度为 n 的序列 的最长递增子序列
        for (int n = 1; n < dp.size(); ++n)
        {
            // nums[n] 依赖任何一个前面的值，所以要遍历它前面的所有数字，找到包含最长子序列的 nums[i]
            // 递推公式 dp[n] = dp[?] + 1 个数值，因为问题规模（序列长度）是以 +1 方式增长的
            for (int i = 0; i < n; ++i)
            {
                // 如果满足递增这个条件
                if (nums[n] > nums[i])
                {
                    // 找到最长的序列
                    dp[n] = max(dp[n], dp[i] + 1);
                }
            }

            // 额外优化：如果比已有记录更大，则暂存起来，避免再循环一次 dp[]
            result = max(result, dp[n]);
        }

        return result;
    }
};

#endif // dp_leet_code_300_longest_increasing_subsequence_h
