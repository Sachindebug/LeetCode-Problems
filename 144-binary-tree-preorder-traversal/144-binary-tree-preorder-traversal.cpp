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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==nullptr) return res;
        TreeNode* curr=root;
        stack<TreeNode*> s;
        s.push(curr);
        while(!s.empty())
        {
            curr=s.top();
            s.pop();
            res.push_back(curr->val);
            if(curr->right) s.push(curr->right);
            if(curr->left)  s.push(curr->left);
        }
        return res;
        
    }
};