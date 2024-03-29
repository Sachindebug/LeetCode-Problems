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
    int minDiffInBST(TreeNode* root) {
        if(root==nullptr) return INT_MAX;
        stack<TreeNode*> s;
        TreeNode* prev=NULL;
        int res=INT_MAX;
        while(root || !s.empty())
        {
            while(root)
            {
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            if(prev && abs((root->val) - (prev->val)) < res) 
                res=abs((root->val) - (prev->val));
            prev=root;
            root=root->right;
            
        }
        return res;
        
        
    }
};