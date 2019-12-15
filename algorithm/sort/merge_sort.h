//
//  merge_sort.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/4/28.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#ifndef sort_merge_sort_h
#define sort_merge_sort_h

#include "util/int_util.h"

void mMerge(int array[], int unsortedArray[], int low, int mid, int high)
{
    // 复制到额外申请的空间中
    for (int i = low; i <= high; i++)
    {
        unsortedArray[i] = array[i];
    }
    
    // 从额外空间 merge 数据到原数据区
    int p1 = low;
    int p2 = mid + 1;
    
    while (low <= high)
    {
        // 将另一序列剩下的所有元素直接复制到原始数组末尾
        if (p1 > mid)
        {
            array[low++] = unsortedArray[p2++];
            continue;
        }
        if (p2 > high)
        {
            array[low++] = unsortedArray[p1++];
            continue;
        }
        // 复制 左区间 数据回原数据区
        if (unsortedArray[p1] <= unsortedArray[p2])
            array[low++] = unsortedArray[p1++];
        
        // 复制 右区间 数据回原数据区
        if (unsortedArray[p1] > unsortedArray[p2])
            array[low++] = unsortedArray[p2++];
    }
}

// 可以在元素个数小于7的时候采用插入排序
void mSort(int array[], int unsortedArray[], int low, int high)
{
    if (low >= high)
        return;
    
    int mid = low + (high - low)/2;

    // 拆分成2个数据区
    mSort(array, unsortedArray, low, mid);
    mSort(array, unsortedArray, mid + 1, high);
    // 合并数据区，只在 mMerge() 函数中做排序
    mMerge(array, unsortedArray, low, mid, high);
}

// 归并排序
void mergeSort(int array[], int arraySize)
{
    auto unsortedArray = (int*)malloc(sizeof(int)*arraySize);
    memset(unsortedArray, 0, arraySize);
    
    mSort(array, unsortedArray, 0, arraySize - 1);
}

#endif // sort_merge_sort_h
