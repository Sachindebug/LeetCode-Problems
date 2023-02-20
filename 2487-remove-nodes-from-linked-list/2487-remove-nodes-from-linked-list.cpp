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
    ListNode *reverse(ListNode * head){
        ListNode *curr=head, *prev=NULL, *nx=NULL;
        while(curr != NULL){
            nx=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nx;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode *curr=reverse(head);
        ListNode* p=curr;
        while(curr!=NULL && curr->next != NULL){
            if(curr->val > curr->next->val)
            {
                curr->next = curr->next->next;
                
            }
                
            else
                curr=curr->next;
                
        }
        return reverse(p);
    }
};