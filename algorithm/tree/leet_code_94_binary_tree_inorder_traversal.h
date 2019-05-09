//
//  leet_code_94_binary_tree_inorder_traversal.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/4/12.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef tree_leet_code_94_binary_tree_inorder_traversal_h
#define tree_leet_code_94_binary_tree_inorder_traversal_h

#include "util/leetCodeUtil.h"

using namespace std;
using TreeNode = treeUtil::TreeNode;

//
//  https://leetcode.com/problems/binary-tree-inorder-traversal/
//  题意： 中序遍历二叉树，非递归
//
class Solution94
{
private:
    stack<pair<TreeNode*, int>> nQueue;             // int = 1 需要先处理左子树, = 0 不需要
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        // 中序遍历，是指根的顺序在中间，顺序是 左子结点 - 分支结点（包含根结点） - 右子结点
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
                // 重新入队，以便先处理它的左子树
                nQueue.push(make_pair(t, 0));

                // 查找并入栈左侧结点，直到最左端
                while (t->left != nullptr)
                {
                    nQueue.push(make_pair(t->left, 0));
                    t = t->left;
                }
            }
            else
            {
                // 当前未处理最左结点
                result.push_back(t->val);

                // 处理它的右子结点
                if (t->right != nullptr)
                    nQueue.push(make_pair(t->right, 1));
            }
        }

        return result;
    }
};

#endif // tree_leet_code_94_binary_tree_inorder_traversal_h
