# 斐波那契数列

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

大家都知道斐波那契数列，现在要求输入一个整数 $n$，请你输出斐波那契数列的第 $n$ 项（从 0 开始，第 0 项为 0）。$n<=39$

## 解题思路

斐波那契数列的递推关系式为
$$
f(n)=f(n-1)+f(n-2)
$$
所以解题思路显而易见。最直观明了的解法是采用递归，递归代码示例为

```C++
long long Fibonacci(unsigned int n) {
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2)
}
```

但稍加思考不难发现，递归解法效率低下重复计算了数列中的许多项。因此需要考虑采用迭代解法。设置两个变量 `fibNMinusTwo` 和 `fibNMinusOne`，根据递推关系式迭代即可。

## 代码示例

```C++
class Solution {
public:
    int Fibonacci(int n) {
        int result[2] = {0, 1};
        if(n < 2) {
            return result[n];
        }
        int fibNMinusTwo = 0;
        int fibNMinusOne = 1;
        int fibN = 0;
        for(int i = 2; i <= n; i++) {
            fibN = fibNMinusTwo + fibNMinusOne;
            fibNMinusTwo = fibNMinusOne;
            fibNMinusOne = fibN;
        }
        return fibN;
    }
};
```

