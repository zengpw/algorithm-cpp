//
//  leet_code_102_binary_tree_level_order_traversal.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/4/11.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef tree_leet_code_102_binary_tree_level_order_traversal_h
#define tree_leet_code_102_binary_tree_level_order_traversal_h

#include <algorithm>
#include <queue>
#include <string>
#include <vector>

#include "leet_code_tree_util.h"

using namespace std;
using TreeNode = treeUtil::TreeNode;

//
//  https://leetcode.com/problems/binary-tree-level-order-traversal/
//  题意： 按层遍历二叉树，用 BFS 实现
//
class Solution102
{
private:
    queue<TreeNode *> nQueue;
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;

        if (root == nullptr)
            return result;

        // clear
        queue<TreeNode *> empty;
        swap(nQueue, empty);

        nQueue.emplace(root);
        while (!nQueue.empty())
        {
            vector<int> level;

            // 一次性处理同一层的所有数据，实现按层处理
            int nums = nQueue.size();
            for (int i = 0; i < nums; ++i)
            {
                auto node = nQueue.front();
                nQueue.pop();

                level.push_back(node->val);
                if (node->left != nullptr) nQueue.emplace(node->left);
                if (node->right != nullptr) nQueue.emplace(node->right);
            }

            result.push_back(level);
        }

        return result;
    }
};

#endif // tree_leet_code_102_binary_tree_level_order_traversal_h
