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
    ListNode* swapNodes(ListNode* head, int k) {
        k--;
        ListNode* p=head,*q=head,*r=head;
        
        while(k--)
        {
            q=q->next;
            p=p->next;
        }
        while(q->next)
        {
            r=r->next;
            q=q->next;
        }
        int temp=r->val;
        r->val=p->val;
        p->val=temp;
        return head;
    }
};