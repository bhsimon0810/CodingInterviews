# 链表中倒数第k个结点

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

输入一个链表，输出该链表中倒数第 $k$ 个结点。

## 解题思路

对于双向链表，要输出链表倒数第 $k$ 个结点很直接的做法是遍历到链表尾部再回退 $k-1$ 步即可。但对于单向链表而言，不能采用回退方法，因此可行的方案是遍历链表的同时记录链表长度 $n$，然后倒数第 $k$ 结点就是正数第 $n-k+1$ 结点，第二次遍历到该结点处打印输出即可。

显然这种方法需要两次遍历，复杂度相对来说更高。因此考虑只需要一次遍历的解法。定义两个指针，在遍历过程中一前一后相差 $k-1$，则当前面指针遍历到链表末尾时后面链表刚好遍历到倒数第 $k$ 结点，直接输出即可。

需要注意的是要考虑到所有输入情况，包括输入链表为空，输入链表长度不足 $k$，以及 $k$ 的取值非法等情况。链表的许多问题都可以通过设置两个链表一快一慢来解决，比如判断链表是有环、链表中间点等，这些问题会在后续的学习刷题中遇到。

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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k == 0)
            return NULL;
        
        ListNode *pAhead = pListHead;
        ListNode *pBehind = pListHead;
        
        for(unsigned int i = 0; i < k - 1; i++) {
            if(pAhead->next)
                pAhead = pAhead->next;
            else
                return NULL;
        }
        
        while(pAhead->next) {
            pAhead = pAhead->next;
            pBehind = pBehind->next;
        }
        return pBehind;
    }
};
```

