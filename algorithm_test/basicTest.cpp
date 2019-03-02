//
//  basicTest.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/11/20.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "algorithm/basic/binarySearch.h"
#include "algorithm/basic/ternarySearch.h"

#define count 15

const int sortedArray[count] = {0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 7, 9};
const int upTernaryArray[count] = {-5, 0, 1, 1, 2, 3, 9, 6, 5, 4, 3, 2, 1, 0, -5};
const int downTernaryArray[count] = {9, 8, 7, 6, 5, 4, 3, -50, -25, -3, 7, 15, 66, 77, 95};

TEST(basicTest, binarySearch)
{
    int position = binarySearch(sortedArray, 0, count - 1, 3);
    EXPECT_EQ(position, 5);
}

TEST(basicTest, upTernarySearch)
{
    int position = ternarySearch(upTernaryArray, 0, count - 1, 0);
    EXPECT_EQ(position, 6);
}

TEST(basicTest, downTernarySearch)
{
    int position = ternarySearch(downTernaryArray, 0, count - 1, 1);
    EXPECT_EQ(position, 7);
}

