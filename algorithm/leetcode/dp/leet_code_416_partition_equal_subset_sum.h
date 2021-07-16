//
//  leet_code_416_partition_equal_subset_sum.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/5/11.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_416_partition_equal_subset_sum_h
#define dp_leet_code_416_partition_equal_subset_sum_h

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

//
//  https://leetcode.com/problems/partition-equal-subset-sum/
//  题意： 判断一个正整数数组 能否 分成 总和相等 的两份, 0-1 背包问题
//
class Solution416
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = accumulate(nums.begin(), nums.end(), 0);

        // 如果 整个数组总和 是奇数，直接返回 false
        if (n % 2 == 1)
            return false;

        // 0-1 背包问题： 要么能填满背包，要么不能
        // 可以把它看成一个背包总容量为 n/2 的背包问题
        n = n / 2;

        // dp[n] -> false = 不能填满背包, true = 能填满背包
        vector<bool> dp(n + 1, false);

        // dp[0] 代表 背包大小 j - nums[i] = 0
        // 如果 j - nums[i] = 0, 即 j = nums[i], 则 nums[i] 能直接填满大小为 j 的背包
        dp[0] = true;

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = n; j >= nums[i]; --j)
            {
                // 填满大小为 11 的背包，可以用 [11], [1, 10], [1, 5, 5]
                // dp[j] = dp[j] || dp[j - nums[x]] || dp[j - nums[y]] || dp[j - nums[z]]...
                dp[j] = dp[j] || dp[j - nums[i]];
            }

            if (dp[n])
                return true;
        }

        return false;
    }
};

#endif // dp_leet_code_416_partition_equal_subset_sum_h
