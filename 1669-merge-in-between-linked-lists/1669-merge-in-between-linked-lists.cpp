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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev = list1;
        ListNode* forward = list1;
        ListNode *temp = list2;
        a--;
        while(a--)
        {
            prev = prev->next;
        }
        b++;
        while(b--)
        {
            forward = forward->next;
        }
        while(temp->next)
        {
            temp=temp->next;
        }
        prev->next = list2;
        temp->next = forward;
        return list1;
        
    }
};