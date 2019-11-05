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
//  题意： 求 "根节点 -> 叶子节点 路径上所有节点值之和 = 给定数 sum" 的所有路径，用 DFS 实现
//
class Solution113
{
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<int> path;
        dfs(root, sum, path);

        return result;
    }

private:
    void dfs(TreeNode *node, const int sum, vector<int> path)
    {
        if (node == nullptr)
            return;

        // 参数 path 是值传递，它需要在子函数中存储不同的值（代表不同的路径）
        path.push_back(node->val);

        // 已经遍历到叶子节点
        if (node->left == nullptr && node->right == nullptr)
        {
            // 符合条件的路径
            if (accumulate(path.begin(), path.end(), 0) == sum)
                result.push_back(path);
        }
        else
        {
            if (node->left != nullptr) dfs(node->left, sum, path);
            if (node->right != nullptr) dfs(node->right, sum, path);
        }
    }
};

#endif // tree_leet_code_113_path_sum_2_h
