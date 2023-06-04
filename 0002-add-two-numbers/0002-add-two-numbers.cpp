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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2,int c=0) {
        
        if(!l1 && !l2)
        {
            if(c)
            {
                return new ListNode(c);
            }
            return nullptr;
        }
        ListNode *head = new ListNode(0);
        if(l1)
        {
            head->val = head->val+l1->val;
        }
        if(l2)
        {
            head->val = head->val+l2->val;
        }
        head->val = head->val+c;
        c=0;
        if((head->val)>=10)
        {
            head->val = (head->val)%10;
            c=1;
        }
        head->next = addTwoNumbers((l1)?l1->next:l1,(l2)?l2->next:l2,c);
        return head;
    }
};