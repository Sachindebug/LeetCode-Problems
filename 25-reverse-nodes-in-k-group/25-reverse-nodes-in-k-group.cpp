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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode *temp=head;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        if(count<k) return head;
        temp=head;
        int b=k;
        b--;
        while(b--)
        {
            temp=temp->next;
        }
    
        ListNode* res=reverseKGroup(temp->next,k);
        temp->next=nullptr;
        ListNode *rev=reversel(head);
       
        ListNode *a=rev;
        while(a->next!=nullptr)
        {
            a=a->next;
        }
        a->next=res;
        
        return rev;
        
    }
    ListNode* reversel(ListNode *head)
    {
        if(!head || !head->next) return head;
        ListNode* p=head;
        ListNode* res=reversel(p->next);
        p->next->next=p;
        p->next=nullptr;
        return res;
    }
    
};