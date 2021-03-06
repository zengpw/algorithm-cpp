//
//  math.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/16.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#ifndef math_math_h
#define math_math_h

// Fibonacci sequence
// f(1) = 1, f(2) = 1, f(3) = f(1) + f(2), f(n) = f(n - 1) + f(n - 2)
//
// last: f(n - 1)
// current: f(n)
//
int fibonacciRecursionTail(int n, int last, int current)
{
    if (n <= 2) return current;
    return fibonacciRecursionTail(n - 1, current, last + current);
}

// Fibonacci 尾递归版本
int fibonacciRecursion(int n)
{
    return fibonacciRecursionTail(n, 1, 1);
}

// Fibonacci 递推循环版本
int fibonacciRecurrence(int n)
{
    int i = 0;
    int j = 1;

    if (n == 0) return i;
    if (n == 1) return j;

    // 复杂一点可以用 DP 查表，简单写法的时候要注意循环次数
    while (n - 2 > 0)
    {
        int t = j;
        j = i + j;
        i = t;
        n--;
    }

    return i + j;
}

// 计算 n 的阶乘 n！ 末尾所含有 0 的个数
// 题解： 递推公式 f(n!) = n/5 + f(n/5!)
int numberOfFactorialEndZero(int n)
{
    if (n < 5) return 0;

    int result = 0;

    while (n > 5)
    {
        result += n/5;
        n = n/5;
    }

    return result;
}

#endif // math_math_h
