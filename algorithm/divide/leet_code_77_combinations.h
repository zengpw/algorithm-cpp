//
//  leet_code_77_combinations.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/10/21.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef divide_leet_code_77_combinations_h
#define divide_leet_code_77_combinations_h

#include "util/leet_code_util.h"

using namespace std;

//
//  https://leetcode.com/problems/combinations/
//  题意： 组合模板题
//
class Solution77
{
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> combine(int n, int k)
    {
        if (n <= 0 || k <= 0 || k > n)
            return result;

        // 初始化递增数组
        vector<int> input;
        input.reserve(n);

        for (int i = 0; i < n; ++i)
        {
            input.push_back(i + 1);
        }

        // 这个递归函数的内核其实是 DFS 思路
        // path 其实起到模拟 stack 的作用
        vector<int> path;
        combineRecursion(input, path, k, 0);

        return result;
    }

private:
    void combineRecursion(vector<int> &nums, vector<int> &path, int k, int start)
    {
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }

        // 当前数量 + 0 (最后一位的场景) + 1 < k
        if (path.size() + (nums.size() - 1 - start) + 1 < k)
            return;

        // 和全排列相似的递归结构，但是内核不同
        //
        //      全排列每次循环，都会固定 第 start 位，并对 [start + 1, nums.size()) 进行排列
        //      组合的第一位入栈后，直接处理下一位，逻辑比 排列 简单很多
        //
        for (int i = start; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            combineRecursion(nums, path, k, i + 1);
            path.pop_back();
        }
    }
};

#endif // divide_leet_code_77_combinations_h
