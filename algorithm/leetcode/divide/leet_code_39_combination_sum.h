//
//  leet_code_39_combination_sum.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/10/22.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef divide_leet_code_39_combination_sum_h
#define divide_leet_code_39_combination_sum_h

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//
//  https://leetcode.com/problems/combination-sum/
//  题意： 组合模板题的变形
//
class Solution39
{
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> path;
        combinationRecursion(candidates, target, path, 0, 0);
        return result;
    }

private:
    void combinationRecursion(vector<int> &candidates, int target, vector<int> &path, int sum, int start)
    {
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        else if (sum > target)
            return;

        for (int i = start; i < candidates.size(); ++i)
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            combinationRecursion(candidates, target, path, sum, i);
            path.pop_back();
            sum -= candidates[i];
        }
    }
};

#endif // divide_leet_code_39_combination_sum_h
