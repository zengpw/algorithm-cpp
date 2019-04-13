//
//  bitwiseTest.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/22.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "util/intUtil.h"

#include "algorithm/basic/bitwise.h"

// test data for bitwise operation
const int twoNumberAppearsOnceArray[16] = {3, 5, 9, 0, 1, 7, 3, 9, 7, 1, 5, 2, 4, 6, 0, 4};
const int twoNumberAppearsOnceArrayResult[2] = {2, 6};

int twoNumberAppearsOnce2Array[13] = {3, 5, 9, 0, 1, 3, 5, 9, 0, 0, 5, 3, 9};

TEST(bitwiseTest, findNumberAppearsOnce)
{
    auto result1 = findNumberAppearsOnce(twoNumberAppearsOnceArray, 16);
    EXPECT_EQ(result1.size(), 2);

    for (const auto& i : result1)
    {
        EXPECT_TRUE(existsInArray(twoNumberAppearsOnceArrayResult, 2, i));
    }
}

TEST(bitwiseTest, findNumberAppearsOnce2)
{
    int result1 = findNumberAppearsOnce2(twoNumberAppearsOnce2Array, 13);
    EXPECT_EQ(result1, 1);
}
