//
//  leet_code_416_partition_equal_subset_sum.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/5/11.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_416_partition_equal_subset_sum_h
#define dp_leet_code_416_partition_equal_subset_sum_h

#include "util/intUtil.h"
#include "util/leetCodeUtil.h"

using namespace std;

//
//  https://leetcode.com/problems/partition-equal-subset-sum/
//  题意： 判断是否能将数据分成 总和相等 的两份, 0-1 背包问题
//
class Solution416
{
public:
    bool canPartition(vector<int>& nums)
    {
        // 如果总和是奇数，直接返回 false
        int n = accumulate(nums.begin(), nums.end(), 0);

        if (n%2 == 1)
            return false;
        else
            n = n/2;

        // 规模为 n
        // false = 不能拆分成多个给定数字, true = 可以拆分
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        // 0-1 问题： 要么选，要么不选
        // 所以和 硬币问题（完全背包） 不同，可选数据在外层循环，而 dp 在内层循环
        for (int i = 0; i < nums.size(); ++i)
        {
            // 只要数据不大于 j, 就可以测试是否符合要求
            for (int j = n; j >= nums[i]; --j)
            {
                dp[j] = dp[j - nums[i]] || dp[j];
            }

            if (dp[n] == true)
                return true;
        }

        return false;
    }
};

#endif // dp_leet_code_416_partition_equal_subset_sum_h
