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
    int diameterOfBinaryTree(TreeNode* root) {
       int res=0;
       int temp=height(root,res);
       return res; 
    }
    int height(TreeNode* root,int &res)
    {
        if(!root) return 0;
        int lh=height(root->left,res);
        int rh=height(root->right,res);
        res=max(res,lh+rh);
        return 1+max(lh,rh);
    }
};