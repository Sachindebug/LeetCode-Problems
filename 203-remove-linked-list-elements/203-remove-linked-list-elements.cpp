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
    ListNode* removeElements(ListNode* head, int key) {
        if(!head) return head;
        ListNode* p=head;
        while(p)
        {
            if(p->val!=key) break;
            p=p->next;
        }
        if(p==nullptr) return p;
        ListNode *q=p->next;
        ListNode *res=p;
        while(q)
        {
            if(q->val!=key)
            {
                p->next=q;
                q=q->next;
                p=p->next;
            }
            else
            {
                q=q->next;
            }
        }
        p->next=q;
        
        return res;
        
    }
};