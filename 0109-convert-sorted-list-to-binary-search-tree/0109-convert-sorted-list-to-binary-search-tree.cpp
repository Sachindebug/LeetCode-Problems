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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return myfun(head,NULL);
    }
    TreeNode* myfun(ListNode* head,ListNode* end)
    {
        if(head==end) return nullptr;
        if(head->next==end) 
        {
            TreeNode* root=new TreeNode(head->val);
            return root;
        }
        
        
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=end && fast->next!=end)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        TreeNode* root=new TreeNode(slow->val);
     
        root->left=myfun(head,slow);
        root->right=myfun(slow->next,end);
        return root;
        
    }
};