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
    ListNode* doubleIt(ListNode* head) {
        pair<int,ListNode*> res = recurse(head);
        if(res.first) 
        {
            ListNode* temp = new ListNode(res.first);
            temp->next = res.second;
            return temp;
        }
        return res.second;
    }
    pair<int,ListNode*> recurse(ListNode* head)
    {
        if(!head) return {0,head};
        pair<int,ListNode*> res = recurse(head->next);
        int a = head->val;
        a = a*2;
        if(res.first)
        {
            a += 1;
        }
        int rem = a%10;
        head->val = rem;
        a = a/10;
        return {a,head};
    }
};