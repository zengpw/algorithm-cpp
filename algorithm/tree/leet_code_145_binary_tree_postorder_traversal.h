//
//  leet_code_145_binary_tree_postorder_traversal.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/11/5.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef tree_leet_code_145_binary_tree_postorder_traversal_h
#define tree_leet_code_145_binary_tree_postorder_traversal_h

#include "util/leet_code_util.h"

using namespace std;
using TreeNode = treeUtil::TreeNode;

//
//  https://leetcode.com/problems/binary-tree-postorder-traversal/
//  题意： 后序遍历二叉树，顺序 -> 左子节点 - 右子节点 - 分支节点
//
class Solution145
{
private:
    stack<TreeNode *> nStack;
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;

        if (root == nullptr)
            return result;

        // clear
        std::stack<TreeNode *> empty;
        swap(nStack, empty);

        //
        //      入栈顺序： 根节点 - 右子节点 - 左子节点
        //      出栈顺序： 左子节点 - 右子节点 - 分支节点 - 根节点
        //
        //      特点： 所有节点都要入栈
        //
        auto node = root;
        auto lastPopNode = root;
        nStack.push(node);

        while (!nStack.empty())
        {
            node = nStack.top();

            if ((node->left == nullptr && node->right == nullptr) ||
                node->left == lastPopNode ||
                node->right == lastPopNode)
            {
                result.push_back(node->val);
                nStack.pop();
                lastPopNode = node;
            }
            else
            {
                if (node->right != nullptr) nStack.push(node->right);
                if (node->left != nullptr) nStack.push(node->left);
            }
        }

        return result;
    }
};

#endif // tree_leet_code_145_binary_tree_postorder_traversal_h
