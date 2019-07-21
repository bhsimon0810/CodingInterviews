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
