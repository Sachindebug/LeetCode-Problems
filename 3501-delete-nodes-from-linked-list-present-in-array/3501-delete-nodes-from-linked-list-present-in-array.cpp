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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *temp = new ListNode(0,head);
        set<int> s(nums.begin(),nums.end());
        ListNode *curr = temp;
        while(curr && curr->next){
            int v = curr->next->val;
            if(s.find(v)!=s.end()){
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
            }
        }
        return temp->next;
    }
};