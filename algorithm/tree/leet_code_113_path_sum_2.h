//
//  leet_code_113_path_sum_2.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/4/13.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef tree_leet_code_113_path_sum_2_h
#define tree_leet_code_113_path_sum_2_h

#include "util/leet_code_util.h"

using namespace std;
using TreeNode = treeUtil::TreeNode;

//
//  https://leetcode.com/problems/path-sum-ii/
//  题意： 求 “根结点 -> 叶子结点 路径上所有结点值之和 = 给定数 sum ” 的所有路径
//
class Solution113
{
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        vector<vector<int>> result;
        vector<int> path;

        dfs(root, sum, path, result);

        return result;
    }

private:
    void dfs(TreeNode* node, int sum, vector<int> path, vector<vector<int>>& result)
    {
        if (node == nullptr)
            return;
        
        // 参数 path 是值传递，它需要在子函数中存储不同的值（代表不同的路径）
        path.push_back(node->val);

        // 已经遍历到叶子结点
        if (node->left == nullptr && node->right == nullptr)
        {
            // 符合条件的路径
            if (accumulate(path.begin(), path.end(), 0) == sum)
                result.push_back(path);
        }
        else
        {
            if (node->left != nullptr)
                dfs(node->left, sum, path, result);

            if (node->right != nullptr)
                dfs(node->right, sum, path, result);
        }
    }
};

#endif // tree_leet_code_113_path_sum_2_h
