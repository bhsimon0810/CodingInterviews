# 合并两个排序的链表

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

## 解题思路

以有序链表 $1\to3\to5\to7$ 和 $2\to4\to6\to8$ 为例，合并后的链表仍然要保持有序，因此要逐次比较两个链表结点数值的大小，并且一次插入到新的链表。可以通过迭代和递归两种方法解决问题。注意要判断输入链表为空的情况。

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
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr) {
            return pHead2;
        }
        if(pHead2 == nullptr) {
            return pHead1;
        }
        ListNode *pMergeHead = nullptr;
        if(pHead1->val <= pHead2->val) {
            pMergeHead = pHead1;
            pMergeHead->next = Merge(pHead1->next, pHead2);
        }
        else {
            pMergeHead = pHead2;
            pMergeHead->next = Merge(pHead1, pHead2->next);
        }
        return pMergeHead;
    }
};

/* 
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode dummy = ListNode(0);
        ListNode *p = &dummy;
        while(pHead1 && pHead2) {
            if(pHead1->val <= pHead2->val) {
                p->next = pHead1;
                p = p->next;
                pHead1 = pHead1->next;
            }
            else {
                p->next = pHead2;
                p = p->next;
                pHead2 = pHead2->next;
            }
        }
        if(pHead1) p->next = pHead1;
        if(pHead2) p->next = pHead2;
        return dummy.next;
    }
};*/
```



