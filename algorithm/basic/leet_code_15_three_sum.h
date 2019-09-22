//
//  leet_code_15_three_sum.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/4/10.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef basic_leet_code_15_three_sum_h
#define basic_leet_code_15_three_sum_h

#include "util/leet_code_util.h"

using namespace std;

//
//  https://leetcode.com/problems/3sum/
//  题意： 计算数组内所有 a + b + c = 0 的组合
//
class Solution15
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> resultGroup;

        if (nums.empty())
            return resultGroup;

        // 先按照从小到大排序
        sort(nums.begin(), nums.end());

        // 循环处理 [最小值, 0) 之间的所有数据，作为第一个值
        // 因为 3 个数之和为 0, 则必须要有 1 个负数，所以可以类似 2 sum, 先固定一个值
        int i = 0;
        while (nums[i] <= 0 && (i + 2) < nums.size())
        {
            // 定义一个从左往右移动的指针 l, 一个从右往左移动的指针 r
            int l = i + 1;
            int r = nums.size() - 1;

            // 如果 nums[i] + nums[l] + nums[r] < 0, 则 l++
            // 如果 nums[i] + nums[l] + nums[r] > 0, 则 r--
            // 如果 nums[i] + nums[l] + nums[r] == 0, 把该组数据加入结果队列, 同时把 l++, r--
            // 循环处理直到 r <= l
            // i, l, r 都需要判断是否和 i++, l--, r++ 重复，否则会返回多余数据
            while (r > l)
            {
                // 要注意处理 自增、自减 过程中的越界问题
                if (nums[i] + nums[l] + nums[r] < 0)
                {
                    while (l + 1 < nums.size() && nums[l] == nums[++l]){}
                }
                else if (nums[i] + nums[l] + nums[r] > 0)
                {
                    while (r - 1 > 0 && nums[r] == nums[--r]){}
                }
                else
                {
                    vector<int> result = {nums[i], nums[l], nums[r]};
                    resultGroup.push_back(result);

                    while (l + 1 < nums.size() && nums[l] == nums[++l]){}
                    while (r - 1 > 0 && nums[r] == nums[--r]){}
                }
            }

            while (i < nums.size() - 1 && nums[i] == nums[++i]){}
        }

        return resultGroup;
    }
};

#endif // basic_leet_code_15_three_sum_h
