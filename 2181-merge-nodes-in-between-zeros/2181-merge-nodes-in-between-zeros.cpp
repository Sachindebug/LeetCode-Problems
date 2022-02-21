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
    ListNode* mergeNodes(ListNode* head) {
        if(head==nullptr) return head;
        int sum=0;
        ListNode* p=head->next;
        while(p!=nullptr && p->val!=0)
        {
            sum+=(p->val);
            p=p->next;
        }
        if(sum==0) return nullptr;
        ListNode *res=new ListNode(sum);
        res->next=mergeNodes(p);
        return res;
        
    }
};