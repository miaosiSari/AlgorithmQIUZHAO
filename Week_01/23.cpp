/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=NULL, *tail=NULL;
        while(true){
            bool notnull = false;
            int min = 0x7fffffff, argmin = -1;
            for(int i = 0; i < lists.size(); ++i)
            {
                if(lists[i] != NULL) 
                {
                    notnull = true;
                    if(lists[i] -> val < min)
                    {
                        min = lists[i] -> val;
                        argmin = i;
                    }
                }
            }
            if(!notnull) return head;
            ListNode* p = new ListNode(min);
            if(!p) return NULL;
            if(!head) 
            {
                head = p;
                tail = p;
            }
            else
            {
                tail -> next = p;
                tail = p;
                p -> next = NULL;
            }
            lists[argmin] = lists[argmin] -> next;
        }
        return head;
    }
};