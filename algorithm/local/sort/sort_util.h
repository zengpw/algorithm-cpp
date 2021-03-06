//
//  int_util.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/4/4.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#ifndef sort_sort_util_h
#define sort_sort_util_h

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

void swapIntArrayElement(int *array, int i, int j)
{
  int k = *(array + i);
  *(array + i) = *(array + j);
  *(array + j) = k;
}

std::string intArray2String(const int *array, int arraySize)
{
  std::stringstream ss;
  std::string arrayString;

  for (int i = 0; i < arraySize; i++) {
    ss << *(array + i);

    arrayString += ss.str();

    if (i < arraySize - 1) {
      arrayString += " ";
    }

    // clear buffer
    ss.str("");
    ss.clear();
  }

  return arrayString;
}

void printIntArray(const int *array, int arraySize)
{
  std::cout << "Array = " << intArray2String(array, arraySize) << std::endl;
}

#endif // sort_sort_util_h
