//
//  insertion_sort.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/4/26.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#ifndef sort_insertion_sort_h
#define sort_insertion_sort_h

#include "sort_util.h"

void insertionSort(int array[], int low, int high)
{
    int arraySize = high - low + 1;
    
    // 外层无序区 [i, high]
    for (int i = low + 1; i <= high; i++)
    {
        int k = i;
        // 内层有序区 [low, j]
        // 从后往前比较
        for (int j = k - 1; j >= low; j--)
        {
            if (array[k] < array[j])
            {
                swapIntArrayElement(array, k--, j);
//                printIntArray(array, arraySize);
            }
            else
            {
                break;
            }
        }
    }
}

#endif // sort_insertion_sort_h
