/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL, *tail=NULL, *p;
        int val;
        while(l1 || l2)
        {
            if(!l1) {
                val = l2 -> val;
                l2 = l2 ->next;
            }
            else if(!l2) {
                val = l1 -> val;
                l1 = l1 -> next;
            }
            else if(l1 -> val <= l2 -> val) {
                val = l1 -> val;
                l1 = l1 -> next;
            }
            else {
                val = l2 -> val;
                l2 = l2 -> next;
            }
            p = new ListNode(val);
            if(!head)
            {
                head = p;
                tail = p;
            }
            else
            {
                tail -> next = p;
                tail = p;
            }
        }
        return head;
    }
};