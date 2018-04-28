//
//  shellSort.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/4/26.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#include "common/intUtil.h"

void shellSort(int array[], int low, int high)
{
    int arraySize = high - low + 1;
    
    // 步长
    int s = 1;
    // 设置步长初始值，要求步长能递减至1
    while (s < (high - low) / 2)
        s = s * 2 + 1;
    
    // 按步长分区，进行插入排序
    // 当 s = 1 时，代码等于普通插入排序
    while (s >= 1)
    {
        // 无序区
        for (int i = low + s; i <= high; i++)
        {
            int k = i;
            // 有序区
            for (int j = k - s; j >= low; j -= s)
            {
                if (array[k] < array[j])
                {
                    swapIntArrayElement(array, k, j);
                    printIntArray(array, arraySize);
                    
                    k -= s;
                }
                else
                {
                    break;
                }
            }
        }
        
        s = s / 2;
    }
}

