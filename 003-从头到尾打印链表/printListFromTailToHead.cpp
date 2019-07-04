/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

/** solution 1
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> prevec;
        if(head != NULL) {
            ListNode *p = head;
            while(p) {
                prevec.push_back(p->val);
                p = p->next;
            }
        }
        vector<int> postvec;
        int i = 0, size = prevec.size();
        while(i < size) {
            postvec.push_back(prevec.back());
            prevec.pop_back();
            i++;
        }
        return postvec;
    }
};
*/
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
