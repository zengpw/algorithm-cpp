//
//  bubbleSortTest.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/4/4.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "bubbleSort.h"

TEST(bubbleSortTest, bubbleSort)
{
    int array[10] = {3, 5, 9, 0, 1, 7, 7, 7, 7, 7};
    int sortedArray[10] = {0, 1, 3, 5, 7, 7, 7, 7, 7, 9};
    
    bubbleSort(array, 0, 9);
    
    EXPECT_STREQ(array2String(array, 10).c_str(), array2String(sortedArray, 10).c_str());
}
