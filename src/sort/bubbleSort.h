//
//  bubbleSort.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/4/4.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#include "common/util.h"

void swap(int T[], int i, int j)
{
    int k = T[i];
    T[i] = T[j];
    T[j] = k;
}

void bubbleSort(int T[], int low, int high)
{
    //遍历序列的次数
    for (int i = low; i <= high; i++)
    {
        //遍历区间 [low, high - i]
        for (int j = low; j < high - i; j++)
        {
            if (T[j] > T[j + 1])
            {
                swap(T, j, j + 1);
                printArray(T, 10);
            }
        }
    }
}
