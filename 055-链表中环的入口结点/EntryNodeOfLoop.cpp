/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next == NULL || pHead->next->next == NULL)
            return NULL;
        ListNode *pSlow = pHead->next;
        ListNode *pFast = pHead->next->next;
        // 先判断链表是否有环
        while(pFast != pSlow)
        {
            if(pFast->next != NULL && pFast->next->next != NULL)
            {
                pFast = pFast->next->next;
                pSlow = pSlow->next;
            }
            else
            {
                return NULL;
            }
        }
        // 若链表有环
        pFast = pHead;
        while(pFast != pSlow)
        {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        return pFast;
    }
};
