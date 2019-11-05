//
//  tree_test.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/4/12.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "algorithm/util/leet_code_util.h"

#include "algorithm/tree/leet_code_94_binary_tree_inorder_traversal.h"
#include "algorithm/tree/leet_code_102_binary_tree_level_order_traversal.h"
#include "algorithm/tree/leet_code_113_path_sum_2.h"
#include "algorithm/tree/leet_code_144_binary_tree_preorder_traversal.h"
#include "algorithm/tree/leet_code_145_binary_tree_postorder_traversal.h"

// 创建完全二叉树
// 形参（指针）不可变，所以需要传（指针的）引用
void createCompleteBinaryTreeFromArray(TreeNode *&node, vector<int> array, int i = 0)
{
    if (i > array.size() - 1 || array[i] == INT_MAX)
        return;

    // create new node
    node = (TreeNode *) malloc(sizeof(TreeNode));
    node->val = array[i];
    node->left = nullptr;
    node->right = nullptr;

    // create children nodes
    createCompleteBinaryTreeFromArray(node->left, array, 2 * i + 1);
    createCompleteBinaryTreeFromArray(node->right, array, 2 * i + 2);
}

TEST(treeTest, p94)
{
    Solution94 solution;

    TreeNode *root;
    vector<int> array = {1, INT_MAX, 2, INT_MAX, INT_MAX, 3};

    createCompleteBinaryTreeFromArray(root, array);
    vector<int> result = solution.inorderTraversal(root);
    EXPECT_EQ(result.size(), 3);
    EXPECT_STREQ(stlUtil::vector2String<int>(result).c_str(), "1 3 2");
}

TEST(treeTest, p102)
{
    Solution102 solution;

    TreeNode *root;
    vector<int> array = {3, 9, 20, INT_MAX, INT_MAX, 15, 7};

    createCompleteBinaryTreeFromArray(root, array);
    vector<vector<int>> result = solution.levelOrder(root);
    EXPECT_EQ(result.size(), 3);
    EXPECT_STREQ(stlUtil::vectorVector2String<int>(result).c_str(), "3; 9 20; 15 7");
}

TEST(treeTest, p113)
{
    Solution113 solution;

    TreeNode *root;
    vector<int> array = {5, 4, 8, 11, INT_MAX, 13, 4, 7, 2, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 1};

    createCompleteBinaryTreeFromArray(root, array);
    vector<vector<int>> result = solution.pathSum(root, 22);
    EXPECT_EQ(result.size(), 2);
    EXPECT_STREQ(stlUtil::vectorVector2String<int>(result).c_str(), "5 4 11 2; 5 8 4 5");
}

TEST(treeTest, p144)
{
    Solution144 solution;

    TreeNode *root;
    vector<int> array = {1, INT_MAX, 2, INT_MAX, INT_MAX, 3};

    createCompleteBinaryTreeFromArray(root, array);
    vector<int> result = solution.preorderTraversal(root);
    EXPECT_EQ(result.size(), 3);
    EXPECT_STREQ(stlUtil::vector2String<int>(result).c_str(), "1 2 3");
}

TEST(treeTest, p145)
{
    Solution145 solution;

    TreeNode *root;
    vector<int> array = {1, INT_MAX, 2, INT_MAX, INT_MAX, 3};

    createCompleteBinaryTreeFromArray(root, array);
    vector<int> result = solution.postorderTraversal(root);
    EXPECT_EQ(result.size(), 3);
    EXPECT_STREQ(stlUtil::vector2String<int>(result).c_str(), "3 2 1");
}
