//
//  heap_sort.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/4/28.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#ifndef sort_heap_sort_h
#define sort_heap_sort_h

#include "sort_util.h"

void minHeapSort(int array[], int n)
{
    // 大小为 n 的数组，根结点为 0, 最后一个分支结点为 n/2 - 1
    // 从最后一个分支结点开始处理，处理所有非叶子结点
    for (int k = n/2 - 1; k >= 0; k--)
    {
        int i = k;

        // 根结点也需要处理
        while (i >= 0)
        {
            // 保存当前结点位置
            int origin = i;

            // 左右子结点、父结点坐标
            int left = 2*i + 1;
            int right = 2*i + 2;
            int parent = (i - 1)/2;

            // 分别和左右子树比较
            // 右子树存在 && 右子树最小 -> 和右子树交换，然后移动到右子树进行处理
            if (right < n &&
                array[right] < array[left] &&
                array[right] < array[i])
            {
                swapIntArrayElement(array, i, right);
                i = right;
            }
            else if (left < n &&
                     array[left] < array[i])
            {
                // 左子树存在 && 左子树最小 -> 和左子树交换，然后移动到左子树进行处理
                swapIntArrayElement(array, i, left);
                i = left;
            }

            // 如果没有交换发生，则上升到父节点进行处理
            if (origin == i)
            {
                // 如果已经是根结点，则退出循环
                if (origin == 0)
                    break;
                else
                    i = parent;
            }
        }
    }

//    printIntArray(array, n);
}

void heapSort(int array[], int length)
{
//    printIntArray(array, length);

    // i 代表无序区的长度
    for (int i = length; i > 1; i--)
    {
        minHeapSort(array, i);
        
        // 将堆顶元素出队
        swapIntArrayElement(array, 0, i - 1);

//        printIntArray(array, length);
    }
}

#endif // sort_heap_sort_h
