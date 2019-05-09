//
//  leet_code_144_binary_tree_preorder_traversal.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/5/6.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef tree_leet_code_144_binary_tree_preorder_traversal_h
#define tree_leet_code_144_binary_tree_preorder_traversal_h

#include "util/leetCodeUtil.h"

using namespace std;
using TreeNode = treeUtil::TreeNode;

//
//  https://leetcode.com/problems/binary-tree-preorder-traversal/
//  题意： 先序遍历二叉树，非递归
//
class Solution144
{
private:
    stack<pair<TreeNode*, int>> nQueue;             // int = 1 需要后处理右子树, = 0 不需要
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        // 顺序： 分支结点（包含根结点） - 左子结点 - 右子结点
        vector<int> result;

        // clear
        std::stack<pair<TreeNode*, int>> empty;
        swap(empty, nQueue);

        if (root != nullptr)
            nQueue.push(make_pair(root, 1));

        while (!nQueue.empty())
        {
            auto node = nQueue.top();
            TreeNode* t = node.first;
            nQueue.pop();

            if (node.second == 1)
            {
                result.push_back(t->val);

                // 将右子树入队
                if (t->right != nullptr)
                    nQueue.push(make_pair(t->right, 1));

                // 重新入队，以便处理左子树
                nQueue.push(make_pair(t, 0));
            }
            else
            {
                if (t->left != nullptr)
                    nQueue.push(make_pair(t->left, 1));
            }
        }

        return result;
    }
};

#endif // tree_leet_code_144_binary_tree_preorder_traversal_h
