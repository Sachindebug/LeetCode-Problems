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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res;
        int x=(l1->val)+(l2->val);
        int carry=x/10;
        x=x%10;
        res= new ListNode(x);
        l1=l1->next;
        l2=l2->next;
        ListNode* p=res;
        while(l1 && l2)
        {
            x=(l1->val)+(l2->val)+carry;
            carry=x/10;
            x=x%10;
            ListNode *temp=new ListNode(x);
            p->next=temp;
            p=temp;
            
            l1=l1->next;
            l2=l2->next;
            
        }
        while(l1)
        {
            x=(l1->val)+carry;
            carry=x/10;
            x=x%10;
            ListNode *temp=new ListNode(x);
            p->next=temp;
            p=temp;
            
            l1=l1->next;
            
        }
        while(l2)
        {
            x=(l2->val)+carry;
            carry=x/10;
            x=x%10;
            ListNode *temp=new ListNode(x);
            p->next=temp;
            p=temp;
            
            l2=l2->next;
            
        }
        if(carry>0)
        {
            ListNode* temp=new ListNode(carry);
            p->next=temp;
        }
        
        return res;
    }
};