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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        {
            return true;
        }
       
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next=reversel(slow->next);
        slow=slow->next;
        while(slow!=nullptr)
        {
            if(head->val!=slow->val) return false;
            slow=slow->next;
            head=head->next;
        }
        
        return true;
    }
    ListNode *reversel(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode* p=head;
        ListNode* res=reversel(head->next);
        p->next->next=p;
        p->next=nullptr;
        return res;
    }
};