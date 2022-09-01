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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int mx=root->val;
        return recurse(root,mx);
    }
    int recurse(TreeNode* root,int mx)
    {
        if(!root) return 0;
        if(root->val>=mx)
        {
            return 1+recurse(root->left,root->val)+recurse(root->right,root->val);
        }
        return recurse(root->left,mx)+recurse(root->right,mx);
    }
};