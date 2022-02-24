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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        ListNode* res=sortList(head->next);
        if(res==nullptr)
        {
            head->next=nullptr;
            return head;
        }
        if(res->val>=head->val)
        {
            head->next=res;
            return head;
        }
        bool found=false;
        ListNode* curr=res;
        while(curr->next!=nullptr)
        {
            if(curr->next->val>=head->val)
            {
                head->next=curr->next;
                curr->next=head;
                found=true;
                break;
            }
            curr=curr->next;
        }
        if(!found)
        {
            curr->next=head;
            head->next=nullptr;
        }
        return res;
    }
};