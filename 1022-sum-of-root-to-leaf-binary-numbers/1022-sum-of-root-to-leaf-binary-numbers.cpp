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
    int ans = 0;
    bool isLeaf(TreeNode* root){
        if(root->left==NULL && root->right==NULL)
            return true;
        return false;
    }
    
    int calculate(vector<int> v){
       int n=0;
        for(int i=0;i<v.size();i++)
            n=n*2+v[i];
        return n; 
    }
    
    void helper(TreeNode* root,vector<int>& path){
        if(!root)return;
        path.push_back(root->val);
        if(isLeaf(root))
            ans += calculate(path);
        helper(root->left,path);
        helper(root->right,path);
        path.pop_back();
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL)
            return 0;
        vector<int> path;
        helper(root,path);
        return ans;
    }
};