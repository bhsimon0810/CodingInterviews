# 变态跳台阶

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级……它也可以跳上 n 级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

## 解题思路

仍然将问题拆解开来处理。令 $f(n)$ 表示 $n$ 级台阶的跳法，若第一步选择一级跳，则剩余 $n - 1$ 级；若第一步选择两级跳，则剩余 $n - 2$ 级；...... ；若第一步选择 $k$ 级跳，则剩余 $n - k$ 级；若第一步选择 $n$ 级跳，则刚好跳上台阶。经分析可知

$$
\begin{aligned}
f(1) &= 1 \\
f(2) &= 1 + f(1) \\
&\cdots \\
f(n) &= 1 + f(1) + \cdots + f(n-1)
\end{aligned}
$$

由于内存限制，仍然优先考虑采用迭代算法。可以设置数列的前 $n$ 项和 $S(n)$，则递推公式为

$$
f(n)=S(n-2)+f(n-1)
$$

根据递推公式可以很简洁地写出对应代码。

## 代码示例

```C++
class Solution {
public:
    int jumpFloorII(int number) {
        int result[2] = {1, 2};
        if(number <= 2) return result[number - 1];
        int sNMinusTwo = 2;
        int fNMinusOne = 2;
        int fN = 0;
        for(int i = 3; i <= number; i++) {
            fN = sNMinusTwo + fNMinusOne;
            sNMinusTwo += fNMinusOne;
            fNMinusOne = fN;
        }
        return fN;
    }
};
```

