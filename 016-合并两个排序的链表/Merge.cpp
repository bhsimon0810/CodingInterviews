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
