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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> res;
        
        recurse(root,res,to_string(root->val));
        return res;
    }
    void recurse(TreeNode* root,vector<string> &res,string t)
    {
        if(!root->left && !root->right)
        {
            res.push_back(t);
            return;
        }
        
        if(root->left) recurse(root->left,res,t+"->"+to_string(root->left->val));
        if(root->right) recurse(root->right,res,t+"->"+to_string(root->right->val));
        
        
    }
};