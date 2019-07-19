# 包含 `min` 函数的栈

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的 `min` 函数，时间复杂度应为$\mathcal{O}(1)$。

## 解题思路

题目要求定义栈的数据结构，在 $\mathcal{O}(1)$ 复杂度下实现返回栈最小元素的功能。因此既需要保留栈的基本功能，又需要求取最小值，可能会想到添加额外变量存储当前最小值，元素入栈出栈在数据栈上执行相应操作，而返回最小值时只需返回该额外变量。但是存在的问题是若弹出当前最小值，该如何将次最小值赋给额外变量。

因此可行的方法是使用两个栈，一个数据栈用来存放数据，一个辅助栈用来存放每次入栈时的元素最小值——要么是辅助栈的栈顶元素，要么是当前入栈元素。那么每次弹出元素时，辅助栈随着数据栈同时弹出栈顶元素，此时的辅助栈顶元素仍然是当前数据栈的最小元素。

## 代码示例

```C++
class Solution {
public:

    stack<int> s_data, s_min;

    void push(int value) {
        s_data.push(value);
        if(s_min.size() == 0 || value <= s_min.top()) {
            s_min.push(value);
        }
    }
    void pop() {
        if(s_data.top() == s_min.top()) {
            s_min.pop();
        }
        s_data.pop();
    }
    int top() {
        return s_data.top();
    }
    int min() {
        return s_min.top();
    }
};
```

