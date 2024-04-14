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
    int helper(TreeNode* root,int i)
    {
        if(root==nullptr) return 0;
        if(!root->left && !root->right && i==0) return root->val;
        return helper(root->left,0)+helper(root->right,1);
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr) return 0;
        if(!root->left && !root->right) return 0;
        return helper(root->left,0)+helper(root->right,1);
        
    }
};