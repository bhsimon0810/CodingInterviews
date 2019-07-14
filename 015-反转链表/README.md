# 反转链表

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

输入一个链表，反转链表后，输出新链表的表头。

## 解题思路

链表反转可以通过迭代和递归两种方法完成，下面分别就这两种方法给出相应的介绍。首先是迭代法，通过循环从链表头部开始反转，需要注意的是，除了要将当前结点 `cur` 的 `next` 指针设置指向前一结点 `prev` 之外，还要记录下一结点 `cur->next` 的地址以免无法访问后续链表。重复这一过程直到链表尾部。

递归法是从链表尾部开始反转。每次递归过程返回的始终是新链表的头结点也就是原链表的尾部结点。

## 代码示例

```C++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

class SolutionI {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL || pHead->next == NULL)
            return pHead;
        ListNode *pPrev = NULL;
        ListNode *pCur = pHead;
        ListNode *newHead = NULL;
        while(pCur) {
            ListNode *pNext = pCur->next;
            if(pNext == NULL)
                newHead = pCur;
            pCur->next = pPrev;
            pPrev = pCur;
            pCur = pNext;
        }
        return newHead;
    }
};


class SolutionII {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL || pHead->next == NULL)
            return pHead;
        ListNode *newHead = ReverseList(pHead->next);
        pHead->next->next = pHead;
        pHead->next = NULL;
        return newHead;
    }
};
```

