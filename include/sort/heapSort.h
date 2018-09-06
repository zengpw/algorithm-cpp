//
//  heapSort.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/4/28.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#ifndef sort_heapSort_h
#define sort_heapSort_h

#include "include/util/intUtil.h"

void heapMin(int array[], int i, int n)
{
    // -------------函数有2个作用：
    //  * 初次建堆时，从后开始整理分支结点，实际上不需要循环处理孩子结点
    //  * 从堆顶删除元素（进行排序）时，从堆顶开始重新建堆
    
    // 结点 i 的左右孩子结点位置分别为 2i + 1, 2i + 2
    while ((2 * i + 1) < n)
    {
        // 存储下一次需要处理的子结点，默认左子树
        int k = 2 * i + 1;
        
        // 如果存在右孩子结点，则选择一个较小的和根结点比较
        // 如果不存在，则直接比较
        if ((2 * i + 2) < n)
        {
            if (array[2 * i + 1] > array[2 * i + 2])
            {
                if (array[i] > array[2 * i + 2])
                {
                    swapIntArrayElement(array, i, 2 * i + 2);
                    // 如果是右孩子发生了交换，则移动到右子树
                    k = 2 * i + 2;
                }
            }
            else
            {
                if (array[i] > array[2 * i + 1])
                {
                    swapIntArrayElement(array, i, 2 * i + 1);
                }
            }
        }
        else
        {
            if (array[i] > array[2 * i + 1])
            {
                swapIntArrayElement(array, i, 2 * i + 1);
            }
        }
        
        // 移动到发生了交换的子树继续处理（针对情况2）
        i = k;
    }
    
    printIntArray(array, n);
}

void heapSort(int array[], int arraySize)
{
    // ------------建堆
    // 从最后一个分支结点开始，遍历前面所有分支结点，将结点与孩子进行调整，使之变成最小堆
    // 最后一个分支结点（非叶子）的位置为 arraySize/2 - 1
    for (int i = arraySize / 2 - 1; i >= 0; i--)
    {
        heapMin(array, i, arraySize);
    }
    
    // ------------堆排序
    // 使用场景：新元素插入数组最后一个位置以后
    // 首先 swap(堆顶，无序区最后一个数据)
    // 然后对无序区重新建堆
    for (int i = arraySize - 1; i >= 1; i--)
    {
        swapIntArrayElement(array, 0, i);
        printIntArray(array, i);
        
        // 此处的 i 代表无序区的长度
        heapMin(array, 0, i);
        
        printIntArray(array, arraySize);
    }
}

#endif // sort_heapSort_h

