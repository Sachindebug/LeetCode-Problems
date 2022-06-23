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
        stack<int> s1;
        stack<int> s2;
        ListNode* temp=l1;
        while(temp)
        {
            s1.push(temp->val);
            temp=temp->next;
        }
        temp=l2;
        int c=0;
        while(temp)
        {
            s2.push(temp->val);
            temp=temp->next;
        }
        ListNode *prev=NULL;
        
        while(!s1.empty() || !s2.empty() || c)
        {
            if(!s1.empty()) 
            {
                c+=s1.top();
                s1.pop();
            }
            if(!s2.empty()) 
            {
                c+=s2.top();
                s2.pop();
            }
            int v=c%10;
            c/=10;
            temp= new ListNode(v);
            temp->next=prev;
            prev=temp;
        }
        return prev;
    }
};