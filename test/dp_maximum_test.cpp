//
//  dp_maximum_test.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/11/6.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "util.h"

#include "algorithm/leetcode/dp/leet_code_5_longest_palindromic_substring.h"
#include "algorithm/leetcode/dp/leet_code_53_maximum_subarray.h"
#include "algorithm/leetcode/dp/leet_code_300_longest_increasing_subsequence.h"
#include "algorithm/leetcode/dp/leet_code_718_maximum_length_of_repeated_subarray.h"

TEST(dpMaximumTest, p5)
{
    Solution5 solution;

    string str1("babad");
    EXPECT_STREQ(solution.longestPalindrome(str1).c_str(), "bab");

    string str2("cbbd");
    EXPECT_STREQ(solution.longestPalindrome(str2).c_str(), "bb");

    string str3("abcda");
    EXPECT_STREQ(solution.longestPalindrome(str3).c_str(), "a");
}

TEST(dpMaximumTest, p53)
{
    Solution53 solution;

    vector<int> input1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result1 = solution.maxSubArray(input1);
    EXPECT_EQ(result1, 6);

    vector<int> input2 = {1};
    int result2 = solution.maxSubArray(input2);
    EXPECT_EQ(result2, 1);
}

TEST(dpMaximumTest, p300)
{
    Solution300 solution;

    vector<int> nums1;
    int expectResult1 = 0;
    int result1 = solution.lengthOfLIS(nums1);
    EXPECT_EQ(result1, expectResult1);

    vector<int> nums2 = {0};
    int expectResult2 = 1;
    int result2 = solution.lengthOfLIS(nums2);
    EXPECT_EQ(result2, expectResult2);

    vector<int> nums3 = {10, 9, 2, 5, 3, 7, 101, 18};
    int expectResult3 = 4;
    int result3 = solution.lengthOfLIS(nums3);
    EXPECT_EQ(result3, expectResult3);
}

TEST(dpMaximumTest, p718)
{
    Solution718 solution;

    vector<int> A1 = {1, 2, 3, 2, 1};
    vector<int> B1 = {3, 2, 1, 4, 7};
    int result1 = solution.findLength(A1, B1);
    EXPECT_EQ(result1, 3);

    vector<int> A2 = {0, 0, 0, 0, 0};
    vector<int> B2 = {0, 0, 0, 0, 0};
    int result2 = solution.findLength(A2, B2);
    EXPECT_EQ(result2, 5);
}
