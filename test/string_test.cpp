//
//  string_test.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/5/13.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "util.h"

#include "algorithm/leetcode/string/leet_code_14_longest_common_prefix.h"
#include "algorithm/leetcode/string/leet_code_28_implement_strstr.h"
#include "algorithm/leetcode/string/leet_code_72_edit_distance.h"

TEST(stringTest, p14)
{
    Solution14 solution;

    vector<string> strs1 = {"flower", "flow", "flight"};
    string result1 = solution.longestCommonPrefix(strs1);
    EXPECT_STREQ(result1.c_str(), "fl");

    vector<string> strs2 = {"dog", "racecar", "car"};
    string result2 = solution.longestCommonPrefix(strs2);
    EXPECT_STREQ(result2.c_str(), "");
}

TEST(stringTest, p28)
{
    Solution28 solution;

    string strA1("hello");
    string strB1("ll");
    int result1 = solution.strStr(strA1, strB1);
    EXPECT_EQ(result1, 2);

    string strA2("aaaaa");
    string strB2("bba");
    int result2 = solution.strStr(strA2, strB2);
    EXPECT_EQ(result2, -1);

    string strA3("mississippi");
    string strB3("issip");
    int result3 = solution.strStr(strA3, strB3);
    EXPECT_EQ(result3, 4);

    string strA4("babba");
    string strB4("bbb");
    int result4 = solution.strStr(strA4, strB4);
    EXPECT_EQ(result4, -1);
}

TEST(stringTest, p72)
{
    Solution72 solution;

    string word1a = "horse";
    string word2a = "ros";
    int resutl1 = solution.minDistance(word1a, word2a);
    EXPECT_EQ(resutl1, 3);

    string word1b = "intention";
    string word2b = "execution";
    int resutl2 = solution.minDistance(word1b, word2b);
    EXPECT_EQ(resutl2, 5);

    string word1c = "";
    string word2c = "a";
    int resutl3 = solution.minDistance(word1c, word2c);
    EXPECT_EQ(resutl3, 1);
}
