//
//  leet_code_94_binary_tree_inorder_traversal.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/4/12.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef tree_leet_code_94_binary_tree_inorder_traversal_h
#define tree_leet_code_94_binary_tree_inorder_traversal_h

#include <algorithm>
#include <stack>
#include <string>
#include <vector>

#include "leet_code_tree_util.h"

using namespace std;
using TreeNode = treeUtil::TreeNode;

//
//  https://leetcode.com/problems/binary-tree-inorder-traversal/
//  题意： 中序遍历二叉树，顺序 -> 左子节点 - 分支节点 - 右子节点
//
class Solution94
{
private:
    stack<TreeNode *> nStack;
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;

        // clear
        std::stack<TreeNode *> empty;
        swap(nStack, empty);
        
        //
        //      入栈顺序： 根节点 - 左子节点
        //      出栈顺序： 左子节点 - 分支节点 - 右子节点
        //
        //      特点： 节点 出栈后，处理它的 右子树（如果存在）
        //
        //          node == nullptr -> 说明没有需要处理的右子树
        //
        auto node = root;

        while (node != nullptr || !nStack.empty())
        {
            while (node != nullptr)
            {
                nStack.push(node);
                node = node->left;
            }

            node = nStack.top();
            nStack.pop();

            result.push_back(node->val);

            node = node->right;
        }

        return result;
    }
};

#endif // tree_leet_code_94_binary_tree_inorder_traversal_h
