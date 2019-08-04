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
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        int pLength1 = GetListLength(pHead1);
        int pLength2 = GetListLength(pHead2);
        ListNode *pLong, *pShort;
        int diff = abs(pLength1 - pLength2);
        if(pLength1 < pLength2) {
            pLong = pHead2;
            pShort = pHead1;
        }
        else {
            pLong = pHead1;
            pShort = pHead2;
        }
        for(int i = 0; i < diff; i++) {
            pLong = pLong->next;
        }
        while((pLong != NULL) && (pShort != NULL) && (pLong != pShort)) {
            pLong = pLong->next;
            pShort = pShort->next;
        }
        return pLong;
    }
    
    int GetListLength(ListNode* pHead) {
        int length = 0;
        ListNode *pNode = pHead;
        while(pNode) {
            length++;
            pNode = pNode->next;
        }
        return length;
    }
};
