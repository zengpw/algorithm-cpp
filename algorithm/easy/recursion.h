//
//  recursion.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/16.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#ifndef easy_recursion_h
#define easy_recursion_h

#include "util/int_util.h"

// Fibonacci sequence
int fibonacciRS(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibonacciRS(n - 1) + fibonacciRS(n - 2);
}

#endif // easy_recursion_h
