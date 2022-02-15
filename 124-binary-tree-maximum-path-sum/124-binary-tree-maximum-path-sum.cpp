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
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        int temp=maxsum(root,res);
        return res;
    }
    int maxsum(TreeNode* root,int &res)
    {
        if(!root) return 0;
        int lh=max(0,maxsum(root->left,res));
        int rh=max(0,maxsum(root->right,res));
        res=max(res,lh+rh+root->val);
        

        return root->val+max(lh,rh);
    }
};