# 用两个栈实现队列

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

用两个栈来实现一个队列，完成队列的 `Push` 和 `Pop` 操作。 队列中的元素为 `int` 类型。

## 解题思路

栈是先进后出结构，队列是先进先出结构。那么考虑到使用两个栈实现队列的基本功能，则假设定义 `stack1` 和 `stack2`。首先向队列中插入元素 A、B、C，即向 `stack1` 中插入元素，此时 `stack2` 为空，此时队列组成示意图为

|  栈尾  | --------> | --------> | 栈顶 |
| :----: | :-------: | :-------: | :--: |
| Stack1 |     A     |     B     |  C   |
| Stack2 |   null    |   null    | null |

当队列弹出元素时，首先将 `stack1` 的所有元素弹出并插入到 `stack2` 中，再从 `stack2` 中依次弹出即可实现队列元素的先进先出，此时的示意图为

|  栈尾  | --------> | --------> | 栈顶 |
| :----: | :-------: | :-------: | :--: |
| Stack1 |   null    |   null    | null |
| Stack2 |     C     |     B     |  A   |

不过需要注意的是，在弹出元素过程中，需要注意插入的元素保存在 `stack1` 里，而最先插入队列的元素位于 `stack2` 的栈顶。因此在弹出元素时，首先需要判断 `stack2` 是否为空

- 栈为空：需要把 `stack1` 中的元素依次弹出并存入 `stack2` 再弹出
- 栈非空：直接弹出 `stack2` 栈顶元素

此外还需要注意判断整个队列是否为空，如果队列为空则没有元素可以弹出。当然从此题出发，还可以考虑如何使用两个队列表示栈。

## 代码示例

```c++
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()) {
            while(!stack1.empty()) {
                int node = stack1.top();
                stack1.pop();
                stack2.push(node);
            }
        }
        if(stack2.empty()) {
            throw "queue is empty!";
        }
        int node = stack2.top();
        stack2.pop();
        return node;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```

