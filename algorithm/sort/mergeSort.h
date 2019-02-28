//
//  mergeSort.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/4/28.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#ifndef sort_mergeSort_h
#define sort_mergeSort_h

#include "util/intUtil.h"

void mMerge(int array[], int unsortedArray[], int low, int mid, int high)
{
    // 复制到额外申请的空间中
    for (int i = low; i <= high; i++)
    {
        unsortedArray[i] = array[i];
    }
    
    // 从额外空间 merge 数据到原数据区
    int s1 = low;
    int s2 = mid + 1;
    int k = low;
    
    while (k <= high)
    {
        // s1 移动完毕
        if (s1 > mid)
        {
            array[k++] = unsortedArray[s2++];
            continue;
        }
        // s2 移动完毕
        if (s2 > high)
        {
            array[k++] = unsortedArray[s1++];
            continue;
        }
        // s1 比 s2 小，复制 s1 数据回原数据区
        if (unsortedArray[s1] <= unsortedArray[s2])
            array[k++] = unsortedArray[s1++];
        
        // s1 比 s2 大，复制 s2 数据回原数据区
        if (unsortedArray[s1] > unsortedArray[s2])
            array[k++] = unsortedArray[s2++];
    }
}

// 排序
// 可以在元素个数小于7的时候采用插入排序
// 本实现中数据分成2部分，实际上是只在 mMerge() 函数中做排序
void mSort(int array[], int unsortedArray[], int low, int high)
{
    if (low >= high)
        return;
    
    int mid = low + (high - low)/2;
    
    // 分成2个数据区
    mSort(array, unsortedArray, low, mid);
    mSort(array, unsortedArray, mid + 1, high);
    // 合并数据区
    mMerge(array, unsortedArray, low, mid, high);
}

// 合并（归并）排序
void mergeSort(int array[], int arraySize)
{
    auto unsortedArray = (int*)malloc(sizeof(int)*arraySize);
    
    memset(unsortedArray, 0, arraySize);
    
    mSort(array, unsortedArray, 0, arraySize - 1);
}

#endif // sort_mergeSort_h

