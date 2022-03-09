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
        if(!head) return head;
        if(!head->next) return head;
        int count=0;
        ListNode *curr=head;
        int data=curr->val;
        while(curr)
        {
            if(curr->val==data) count++;
            else break;
            curr=curr->next;
        }
        if(count==1) 
        {
            head->next=deleteDuplicates(curr);
            return head;
        }
        return deleteDuplicates(curr);
    }
};