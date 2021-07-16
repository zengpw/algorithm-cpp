//
//  sort_test.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/4/4.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "gtest/gtest.h"

#include "util.h"

#include "algorithm/local/sort/bubble_sort.h"
#include "algorithm/local/sort/heap_sort.h"
#include "algorithm/local/sort/insertion_sort.h"
#include "algorithm/local/sort/merge_sort.h"
#include "algorithm/local/sort/quick_sort.h"
#include "algorithm/local/sort/selection_sort.h"
#include "algorithm/local/sort/shell_sort.h"

#define count 15
#define arraySize sizeof(int)*count

const int unsortedArray[count] = {3, 5, 9, 0, 1, 7, 7, 7, 7, 7, 1, 2, 4, 6, 0};
const int sortedArray[count] = {0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 7, 9};

int* createTestArray()
{
    auto array = (int*)malloc(arraySize);
    memcpy(array, unsortedArray, arraySize);
    
    std::cout << std::endl;
//    printIntArray(array, count);
    
    return array;
}

TEST(sortTest, bubbleSort)
{
    int* array = createTestArray();
    
    bubbleSort(array, 0, count - 1);
    EXPECT_STREQ(intArray2String(array, count).c_str(), intArray2String(sortedArray, count).c_str());
    
    free(array);
}

TEST(sortTest, selectionSort)
{
    int* array = createTestArray();
    
    selectionSort(array, 0, count - 1);
    EXPECT_STREQ(intArray2String(array, count).c_str(), intArray2String(sortedArray, count).c_str());
    
    free(array);
}

TEST(sortTest, insertionSort)
{
    int* array = createTestArray();
    
    insertionSort(array, 0, count - 1);
    EXPECT_STREQ(intArray2String(array, count).c_str(), intArray2String(sortedArray, count).c_str());
    
    free(array);
}

TEST(sortTest, shellSort)
{
    int* array = createTestArray();
    
    shellSort(array, 0, count - 1);
    EXPECT_STREQ(intArray2String(array, count).c_str(), intArray2String(sortedArray, count).c_str());
    
    free(array);
}

TEST(sortTest, mergeSort)
{
    int* array = createTestArray();
    
    mergeSort(array, count);
    EXPECT_STREQ(intArray2String(array, count).c_str(), intArray2String(sortedArray, count).c_str());
    
    free(array);
}

TEST(sortTest, quickSort)
{
    int* array = createTestArray();
    
    quickSort(array, 0, count - 1);
    EXPECT_STREQ(intArray2String(array, count).c_str(), intArray2String(sortedArray, count).c_str());
    
    free(array);
}

TEST(sortTest, heapSort)
{
    int* array = createTestArray();

    heapSort(array, count);

    std::string result = intArray2String(array, count);
    reverse(result.begin(), result.end());

    EXPECT_STREQ(result.c_str(), intArray2String(sortedArray, count).c_str());

    free(array);
}
