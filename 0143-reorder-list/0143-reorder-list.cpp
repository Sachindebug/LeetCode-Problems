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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        stack<ListNode*> s;
        ListNode* p=head;
        while(p)
        {
            s.push(p);
            p=p->next;
        }
        p=head;
        ListNode* q;
        ListNode* r;
        int sz=s.size();
        for(int i=0;i<sz/2;i++)
        {
            
            
            r=s.top();
            
            s.pop();
            r->next=p->next;
            p->next=r;
            p=p->next->next;
        }
        p->next=nullptr;
        
    }
};