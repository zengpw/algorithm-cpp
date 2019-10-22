//
//  leet_code_47_permutations_ii.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/10/21.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef divide_leet_code_47_permutations_ii_h
#define divide_leet_code_47_permutations_ii_h

#include "util/leet_code_util.h"

using namespace std;

//
//  https://leetcode.com/problems/permutations-ii/
//  题意： 全排列（需要去重）模板题
//
class Solution47
{
private:
    set<vector<int>> resultSet;
    vector<vector<int>> result;
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        permuteRecursion(nums, 0);
        // 全排列的思维 + 去重
        copy(resultSet.begin(), resultSet.end(), inserter(result, result.end()));
        return result;
    }

private:
    void permuteRecursion(vector<int> &nums, int start)
    {
        if (start == nums.size() - 1)
        {
            resultSet.insert(nums);
            return;
        }

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

#endif // divide_leet_code_47_permutations_ii_h
