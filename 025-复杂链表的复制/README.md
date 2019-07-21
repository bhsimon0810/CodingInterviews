# 复杂链表的复制

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

输入一个复杂链表（每个结点中有结点值，以及两个指针，一个指向下一个结点，另一个特殊指针指向任意一个结点），返回结果为复制后复杂链表的 `head`。（注意，输出结果中请不要返回参数中的结点引用，否则判题程序会直接返回空）

## 解题思路

对于复杂链表的复制，首先来看具体需要完成的要求。复杂链表除了包括指向下一结点的指针外，还有随即指针指向任意结点（包括为空），示意图如下，其中实线表示指向下一结点指针，虚线表示随即指针。

![ComplexList](http://wx1.sinaimg.cn/mw690/a9d96161ly1g57r3hugqjj209g04w747.jpg)

因此一个可行的方法是，第一次遍历沿着 `next` 指针，新建链表并把对应结点复制下来；然后第二次遍历，对某一结点 $N$，随机指针指向结点 $S$，因为结点 $S$ 位置的不确定性，使得每次对结点 $S$ 的定位必须从链表头结点遍历直至得到结点 $S$ 的位置信息 $k$，然后从新链表头结点开始遍历 $k$ 步得到复制结点 $N^{\prime}$ 的随即指针指向的结点 $S^{\prime}$。这种方法的复杂度是 $\mathcal{O}(n^2)$，因此需要考虑复杂度更优的解法。

上述方法的复杂度主要在与结点 $S$ 的定位，因此借助哈希表 `map` 可以实现 $\mathcal{O}(1)$ 复杂度的查找。第一次遍历链表的时候，同时建立哈希表 $<N,N^{\prime}>$，键为原始链表的结点指针，值为复制链表的结点指针。这样在第二次遍历链表的时候，结点 $N$ 的随即指针指向 $S$，则在新的复制链表中对结点 $S^{\prime}$ 的定位可直接通过哈希表 $<S,S^{\prime}>$ 找到。这样算法的时间复杂度是 $\mathcal{O}(n)$，空间复杂度是 $\mathcal{O}(n)$，通过以空间换时间完成算法时间复杂度的优化。

再继续思考，还有更优的解法。归根结底算法核心在于如何通过原始链表的结点 $S$ 快速定位出复制链表的结点 $S^{\prime}$。因此如果把新的复制结点插入至原始链表结点的后面，则可以简洁方便定位出来，最后将原始链表和复制链表分离出来即可。

![ComplexList2](http://wx1.sinaimg.cn/mw690/a9d96161ly1g57s34u5u4j20nv0k9mzx.jpg)

第一步将复制的链表结点插入到对应结点后面，此时 `next` 指针指示的链表顺序仍保持不变；第二步复制结点的 `random` 指针所指向的结点 $S^\prime$ 位于结点 $S$ 之后，可以很方便地与复制结点 $N^{\prime}$ 连接起来；第三步就是恢复出原始链表和复制链表，注意边界条件地判断。

## 代码示例

```C++
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL) return NULL;

        // 复制链表 next 结点并插入到原始链表中
        RandomListNode *pNode = pHead;
        while(pNode) {
            RandomListNode *pCloneNode = new RandomListNode(pNode->label);
            pCloneNode->next = pNode->next;
            pNode->next = pCloneNode;
            pNode = pCloneNode->next;
        }

        // 复制链表 random 指针所指向结点
        pNode = pHead;
        while(pNode) {
            RandomListNode *pCloneNode = pNode->next;
            if(pNode->random) {
                pCloneNode->random = pNode->random->next;
            }
            pNode = pCloneNode->next;
        }

        // 将原始链表和复制链表拆分
        pNode = pHead;
        RandomListNode dummyNode = RandomListNode(0);
        dummyNode.next = pNode;
        RandomListNode *pCloneNode = &dummyNode;
        
        while(pNode) {
            pCloneNode->next = pNode->next;
            pCloneNode = pCloneNode->next;
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }

        return dummyNode.next;
    }
};
```

