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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        // 如果链表为空或者只包含一个结点，直接返回
        if(pHead == NULL || pHead->next == NULL)
            return pHead;
        // 设置哑结点和双指针
        ListNode dummyNode = ListNode(0);
        dummyNode.next = pHead;
        ListNode *prev = &dummyNode;
        ListNode *cur = dummyNode.next;
        while(cur != NULL)
        {
            // 判断链表结点是否重复
            if(cur->next != NULL && cur->next->val == cur->val)
            {
                while(cur->next != NULL && cur->next->val == cur->val)
                    cur = cur->next;
                prev->next = cur->next;
                cur = cur->next;
            }
            else
            {
                prev = prev->next;
                cur = cur->next;
            }
        }
        return dummyNode.next;
    }
};
