//
//  leet_code_28_implement_strstr.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/5/15.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_28_implement_strstr_h
#define dp_leet_code_28_implement_strstr_h

#include "util/intUtil.h"
#include "util/leetCodeUtil.h"

using namespace std;

//
//  https://leetcode.com/problems/implement-strstr/
//  题意： 求子串位置，用 KMP 算法
//
class Solution28
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;

        if (needle.length() > haystack.length())
            return -1;

        int next[needle.size()];
        memset(next, 0, sizeof(next));

        // generate Next array for KMP
        generateNext(needle, next);

        for (int i = 0, j = 0; i < haystack.length();)
        {
            // 匹配到，则同时移动
            while (haystack[i] == needle[j])
            {
                if (j == needle.length() - 1)
                    return i - j;

                i++;
                j++;
            }

            // 特殊情况： 子串首位不匹配，移动母串
            if (j == 0)
            {
                i++;
            }
            else
            {
                // KMP 中，非首位发生不匹配时，母串位置不变，子串位置回移
                int sub = (j - 1 >= 0) ? j - 1 : 0;
                // KMP 算法移动位数 = 已匹配的字符数 - 对应的部分匹配值
                // 因为 j 既代表子串首地址，也用来计算需要移动的位数
                // 原始公式 j = j - (j - next[sub]), 简写如下
                j = next[sub];
            }
        }

        return -1;
    }
private:
    void generateNext(string needle, int next[])
    {
        for (int i = 1; i < needle.length(); ++i)
        {
            // s 是长度，所以 s + 1 在子串中的下标为 needle[s]
            int s = next[i - 1];
            
            // 如果 next[i - 1] 存在部分匹配，并且 新的元素 不匹配
            while (s > 0 && needle[s] != needle[i])
                s = next[s - 1];

            // 如果 needle[s] == needle[i], 则 next[i] 相对 next[i - 1] 长度 +1
            if (needle[s] == needle[i])
                next[i] = s + 1;
            else
                next[i] = 0;
        }
    }
};

#endif // dp_leet_code_28_implement_strstr_h
