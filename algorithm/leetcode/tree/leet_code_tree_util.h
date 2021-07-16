//
//  leet_code_tree_util.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2021/7/15.
//  Copyright © 2021 Vincent Zeng. All rights reserved.
//

#ifndef tree_leet_code_tree_util_h
#define tree_leet_code_tree_util_h

#include <algorithm>

namespace treeUtil
{
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     * };
     */

    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL)
        {}
    };
}

#endif // tree_leet_code_tree_util_h
