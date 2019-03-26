//
//  basicTest.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/11/20.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "algorithm/basic/binarySearch.h"
#include "algorithm/basic/recurrence.h"
#include "algorithm/basic/recursion.h"
#include "algorithm/basic/ternarySearch.h"

// test data for recursion, recurrence, iteration
const int fibonacci[30] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34,
                           55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181,
                           6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229};

// test data for array search
#define count 15
const int sortedArray[count] = {0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 7, 9};
const int upTernaryArray[count] = {-5, 0, 1, 1, 2, 3, 9, 6, 5, 4, 3, 2, 1, 0, -5};
const int downTernaryArray[count] = {9, 8, 7, 6, 5, 4, 3, -50, -25, -3, 7, 15, 66, 77, 95};

TEST(basicTest, fibonacciRS)
{
    int result1 = fibonacciRS(15);
    EXPECT_EQ(result1, 610);

    int result2 = fibonacciRS(25);
    EXPECT_EQ(result2, 75025);
}

TEST(basicTest, fibonacciRR)
{
    int result1 = fibonacciRR(15);
    EXPECT_EQ(result1, 610);

    int result2 = fibonacciRR(25);
    EXPECT_EQ(result2, 75025);
}

TEST(basicTest, binarySearch)
{
    int position = binarySearch(sortedArray, 0, count - 1, 3);
    EXPECT_EQ(position, 5);
}

TEST(basicTest, ternarySearchUp)
{
    int position = ternarySearch(upTernaryArray, 0, count - 1, 0);
    EXPECT_EQ(position, 6);
}

TEST(basicTest, ternarySearchDown)
{
    int position = ternarySearch(downTernaryArray, 0, count - 1, 1);
    EXPECT_EQ(position, 7);
}
