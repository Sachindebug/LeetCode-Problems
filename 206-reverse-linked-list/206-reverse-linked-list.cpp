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
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        ListNode *p=head;
        ListNode *q=nullptr;
        ListNode *r=nullptr;
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;

        
        
    }
};