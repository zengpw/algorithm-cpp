//
//  dpTest.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/4.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "algorithm/util/leetCodeUtil.h"

#include "algorithm/dp/leet_code_5_longest_palindromic_substring.h"
#include "algorithm/dp/leet_code_14_longest_common_prefix.h"
#include "algorithm/dp/leet_code_279_perfect_squares.h"
#include "algorithm/dp/leet_code_300_longest_increasing_subsequence.h"
#include "algorithm/dp/leet_code_322_coin_change.h"
#include "algorithm/dp/leet_code_718_maximum_length_of_repeated_subarray.h"
#include "algorithm/dp/leet_code_887_super_egg_drop.h"

TEST(dpTest, p5)
{
    Solution5 solution;

    string str1("babad");
    EXPECT_STREQ(solution.longestPalindrome(str1).c_str(), "bab");

    string str2("cbbd");
    EXPECT_STREQ(solution.longestPalindrome(str2).c_str(), "bb");

    string str3("abcda");
    EXPECT_STREQ(solution.longestPalindrome(str3).c_str(), "a");
}

TEST(dpTest, p14)
{
    Solution14 solution;

    vector<string> strs1 = {"flower", "flow", "flight"};
    string result1 = solution.longestCommonPrefix(strs1);
    EXPECT_STREQ(result1.c_str(), "fl");

    vector<string> strs2 = {"dog", "racecar", "car"};
    string result2 = solution.longestCommonPrefix(strs2);
    EXPECT_STREQ(result2.c_str(), "");
}

TEST(dpTest, p279)
{
    Solution279 solution;

    int input1 = 12;
    int expectResult1 = 3;
    int result1 = solution.numSquares(input1);
    EXPECT_EQ(result1, expectResult1);

    int input2 = 13;
    int expectResult2 = 2;
    int result2 = solution.numSquares(input2);
    EXPECT_EQ(result2, expectResult2);
}

TEST(dpTest, p300)
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

TEST(dpTest, p322)
{
    Solution322 solution;

    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    int expectResult1 = 3;
    int result1 = solution.coinChange(coins1, amount1);
    EXPECT_EQ(result1, expectResult1);

    vector<int> coins2 = {2};
    int amount2 = 3;
    int expectResult2 = -1;
    int result2 = solution.coinChange(coins2, amount2);
    EXPECT_EQ(result2, expectResult2);

    vector<int> coins3 = {186, 419, 83, 408};
    int amount3 = 6249;
    int expectResult3 = 20;
    int result3 = solution.coinChange(coins3, amount3);
    EXPECT_EQ(result3, expectResult3);
}

TEST(dpTest, p718)
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

TEST(dpTest, p887)
{
    Solution887 solution;

    int result = solution.superEggDrop(2, 100);
    EXPECT_EQ(result, 14);
}