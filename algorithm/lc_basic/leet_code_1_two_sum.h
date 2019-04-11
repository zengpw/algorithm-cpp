//
//  leet_code_1_two_sum.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/4/10.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef lc_basic_leet_code_1_two_sum_h
#define lc_basic_leet_code_1_two_sum_h

#include "util/leetCodeUtil.h"

using namespace std;

//
//  https://leetcode.com/problems/two-sum/
//  题意： 已知存在 a + b = c, 根据 c 和 a, b 的超集求 a, b 的下标
//
class Solution1
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        // <值, 数组下标>
        unordered_map<int, int> numMap;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i)
        {
            int expectNum = target - nums[i];

            if (numMap.count(expectNum) > 0)
            {
                result.push_back(numMap[expectNum]);
                result.push_back(i);
                break;
            }
            else
            {
                // 如果不存在，则把这个数加入到查找列表
                numMap[nums[i]] = i;
            }
        }

        return result;
    }
};

#endif // lc_basic_leet_code_1_two_sum_h
