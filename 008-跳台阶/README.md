# 跳台阶

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

## 解题思路

令 $f(n)$ 表示 $n$ 级台阶的跳法

- 当 $n=1$ 时，只有一种跳法，即 $f(1) = 1$
- 当 $n=2$ 时可以选择一级一级跳，也可以选择两级跳共两种跳法，即 $f(2) = 2$
- 当 $n > 2$ 时将问题拆解，第一跳可以选择一级跳，则剩余 $n-1$ 级台阶；第一跳选择两级跳，则剩余 $n - 2$ 级台阶。即 $f(n) = f(n-1) + f(n-2)$

经分析可知，跳台阶实质上仍是斐波那契数列问题，采用迭代解法即可。

## 代码示例

```C++
class Solution {
public:
    int jumpFloor(int number) {
        int result[2] = {1, 2};
        if(number <= 2) return result[number - 1];

        int fibNMinusTwo = 1;
        int fibNMinusOne = 2;
        int fibN = 0;
        for(int i = 3; i <= number; i++) {
            fibN = fibNMinusTwo + fibNMinusOne;
            fibNMinusTwo = fibNMinusOne;
            fibNMinusOne = fibN;
        }
        return fibN;
    }
};
```

