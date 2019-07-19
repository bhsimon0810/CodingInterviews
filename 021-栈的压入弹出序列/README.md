# 栈的压入弹出序列

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列 1, 2, 3, 4, 5 是某栈的压入顺序，序列 4, 5, 3, 2, 1 是该压栈序列对应的一个弹出序列，但 4, 3, 5, 1, 2 就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

## 解题思路

序列一是栈的压入顺序，判断序列二是否为可能的弹出顺序，并假设压入栈的所有元素均不相等。这是非常典型的算法题目，借助辅助栈按序列一顺序将所有元素入栈再弹出，与序列二比对即可。

以序列 1 2 3 4 5 为例，压入元素 4 之后弹出，再压入元素 5 并弹出，再依次弹出栈中所有元素即得到序列 4 5 3 2 1。根据同样的方法可判断 4 3 5 1 2 不可能是弹出序列。

因此判断栈的压入弹出序列方法是，每次序列一中的元素入栈后，比较序列二当前元素是否为栈顶元素，若不是栈顶元素则继续对序列一元素入栈；若是栈顶元素，则执行弹出操作，继续比较新的栈顶元素与序列二下一位置元素。比较过程中要注意各种边界条件，栈只有非空才可以弹出元素，以及检查数组越界等等。

## 代码示例

```C++
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() == 0 || popV.size() == 0)
            return false;
        stack<int> s;
        for(int pushIndex, popIndex = 0; pushIndex < pushV.size(); pushIndex++) {
            s.push(pushV[pushIndex]);
            while(!s.empty() && popIndex < popV.size() && s.top() == popV[popIndex]) {
                s.pop();
                popIndex++;
            }
        }
        return s.empty();
    }
};
```

