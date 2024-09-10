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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next) return head;
        ListNode *prev=head, *next=head->next;
        while(next)
        {
            int a = prev->val;
            int b = next->val;
            int c = __gcd(a,b);
            ListNode *temp = new ListNode(c);
            prev->next = temp;
            temp->next = next;
            prev=next;
            next=next->next;
        }
        return head;
    }
};