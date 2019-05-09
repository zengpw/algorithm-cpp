//
//  leet_code_102_binary_tree_level_order_traversal.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/4/11.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef tree_leet_code_102_binary_tree_level_order_traversal_h
#define tree_leet_code_102_binary_tree_level_order_traversal_h

#include "util/leetCodeUtil.h"

using namespace std;
using TreeNode = treeUtil::TreeNode;

//
//  https://leetcode.com/problems/binary-tree-level-order-traversal/
//  题意： 按层遍历二叉树
//
class Solution102
{
private:
    queue<TreeNode*> nQueue;
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        // 整体思路是用 BFS 实现
        vector<vector<int>> resultGroup;

        // clear
        queue<TreeNode*> empty;
        swap(empty, nQueue);

        if (root == nullptr)
            return resultGroup;
        else
            nQueue.emplace(root);

        while (!nQueue.empty())
        {
            // 一次性处理同一层的所有数据，实现按层处理
            int size = nQueue.size();
            vector<int> values;

            for (int i = 0; i < size; ++i)
            {
                TreeNode* node = nQueue.front();
                nQueue.pop();

                values.push_back(node->val);
                if (node->left != nullptr) nQueue.emplace(node->left);
                if (node->right != nullptr) nQueue.emplace(node->right);
            }

            resultGroup.push_back(values);
        }

        return resultGroup;
    }
};

#endif // tree_leet_code_102_binary_tree_level_order_traversal_h
