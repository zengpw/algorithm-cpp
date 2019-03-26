//
//  recursion.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/16.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#ifndef basic_recursion_h
#define basic_recursion_h

#include "util/intUtil.h"

// Fibonacci sequence
int fibonacciRS(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibonacciRS(n - 1) + fibonacciRS(n - 2);
}

#endif // basic_recursion_h
