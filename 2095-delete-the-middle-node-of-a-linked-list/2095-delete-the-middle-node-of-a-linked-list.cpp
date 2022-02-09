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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr) return nullptr;
        if(head->next->next==nullptr) 
        {
            head->next=nullptr;
            return head;
        }
        ListNode* p=head;
        ListNode* q=head;
        while(q->next && q->next->next)
        {
            p=p->next;
            q=q->next->next;
        }
        if(q->next!=nullptr) p=p->next;
        p->val=p->next->val;
        p->next=p->next->next;
        return head;
        
    }
};