//
//  leet_code_53_maximum_subarray.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/5/11.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_53_maximum_subarray_h
#define dp_leet_code_53_maximum_subarray_h

#include "util/int_util.h"
#include "util/leet_code_util.h"

using namespace std;

//
//  https://leetcode.com/problems/maximum-subarray/
//  题意： 求最大连续子序列和
//
class Solution53
{
public:
    int maxSubArray(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;

        int result = 0;

        vector<int> dp(nums.size(), 0);
        result = dp[0] = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            if (dp[i - 1] > 0)
                dp[i] = dp[i - 1] + nums[i];
            else
                dp[i] = nums[i];

            result = max(result, dp[i]);
        }

        return result;
    }
};

#endif // dp_leet_code_53_maximum_subarray_h
