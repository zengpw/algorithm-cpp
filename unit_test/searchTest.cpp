//
//  searchTest.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/9/6.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "include/search/binarySearch.h"

#define count 15

const int sortedArray[count] = {0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 7, 9};

TEST(searchTest, binarySearch)
{
    int position = binarySearch(sortedArray, 0, count - 1, 3);
    EXPECT_EQ(position, 5);
}
