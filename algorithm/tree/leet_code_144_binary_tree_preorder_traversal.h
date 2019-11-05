//
//  leet_code_144_binary_tree_preorder_traversal.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/5/6.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef tree_leet_code_144_binary_tree_preorder_traversal_h
#define tree_leet_code_144_binary_tree_preorder_traversal_h

#include "util/leet_code_util.h"

using namespace std;
using TreeNode = treeUtil::TreeNode;

//
//  https://leetcode.com/problems/binary-tree-preorder-traversal/
//  题意： 先序遍历二叉树，顺序 -> 分支节点 - 左子节点 - 右子节点
//
class Solution144
{
private:
    stack<TreeNode *> nStack;
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;

        // clear
        std::stack<TreeNode *> empty;
        swap(nStack, empty);

        //
        //      入栈顺序： 分支节点（打印 + 入栈） - 左子节点
        //      出栈顺序： 左子节点 - 分支节点
        //
        //      特点： 节点 出栈后，处理它的 右子树（如果存在）
        //
        auto node = root;
        
        while (node != nullptr || !nStack.empty())
        {
            if (node != nullptr)
            {
                result.push_back(node->val);
                
                nStack.push(node);
                node = node->left;
            }
            else
            {
                node = nStack.top();
                nStack.pop();
                node = node->right;
            }
        }

        return result;
    }
};

#endif // tree_leet_code_144_binary_tree_preorder_traversal_h
