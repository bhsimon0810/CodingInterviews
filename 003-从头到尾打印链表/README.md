# 从尾到头到头打印链表

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

输入一个链表，按链表值从尾到头的顺序返回一个 ArrayList。

## 解题思路

仿照反转链表的思路，将链表反向打印即可。注意因为函数返回值类型是 `vector<int>`，因此不好使用递归方法。可行的思路是采用循环将链表每个节点的值保存到容器，再对容器反转打印输出。

## 代码示例

```C++
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vec;
        if(head != NULL) {
            ListNode *p = head;
            while(p) {
                vec.push_back(p->val);
                p = p->next;
            }
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};
```

