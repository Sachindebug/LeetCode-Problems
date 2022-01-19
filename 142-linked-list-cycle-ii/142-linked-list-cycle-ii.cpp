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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p=head,*q=head;
        bool cycle=false;
        while(q!=nullptr && q->next!=nullptr)
        {
            p=p->next;
            q=q->next->next;
            if(p==q)
            {
                cycle=true;
                break;
                
            }
        }
        if(!cycle)
        {
            return nullptr;
        }
        p=head;
        while(p!=q)
        {
            p=p->next;
            q=q->next;
        }
        return p;
        
    }
};