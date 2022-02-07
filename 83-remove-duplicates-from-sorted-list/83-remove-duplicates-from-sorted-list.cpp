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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        ListNode* p=head->next;
        ListNode* q=head;
        
        while(p!=nullptr)
        {
            if(p->val!=q->val)
            {
                q=p;
                p=p->next;
            }
            else
            {
                q->next=p->next;
                delete p;
                p=q->next;
                
                
            }
        }
        return head;
    }
};