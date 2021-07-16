//
//  leet_code_46_permutations.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/10/18.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef divide_leet_code_46_permutations_h
#define divide_leet_code_46_permutations_h

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//
//  https://leetcode.com/problems/permutations/
//  题意： 全排列模板题
//
class Solution46
{
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        permuteRecursion(nums, 0);
        return result;
    }

private:
    void permuteRecursion(vector<int> &nums, int start)
    {
        // 当排列区间为 [n, n] 时，实际上不需要排列，此时为全排列的其中一种情况
        if (start == nums.size() - 1)
        {
            result.push_back(nums);
            return;
        }

        // 每次大循环，固定 start 位，并排列所有的 [start + 1, nums.size())
        //
        //      i = start 并且 swap(nums, start, i), 意味着第一次循环，是固定“初始” start 位，循环后面部分
        //      当 i 递增时，比如 swap(nums, 0, 5) 以后，调用函数排列 [1, 5], 实际上固定了 第 i 位
        //      一定要理解，当 i 递增（并交换）时，始终固定第 i 位，而不是第 i + 1 位，然后排列后面的区间
        //
        for (int i = start; i < nums.size(); ++i)
        {
            swap(nums, start, i);
            permuteRecursion(nums, start + 1);
            swap(nums, start, i);
        }
    }

    void swap(vector<int> &nums, int x, int y)
    {
        int t = nums[x];
        nums[x] = nums[y];
        nums[y] = t;
    }
};

#endif // divide_leet_code_46_permutations_h
