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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==nullptr)
        {
            return res;
        }
        stack<TreeNode*> s;
        TreeNode* curr=root;
        
        while(curr || !s.empty())
        {
            if(curr)
            {
                s.push(curr);
                curr=curr->left;
            }
            else
            {
                curr=s.top();
                res.push_back(curr->val);
                s.pop();
               
                curr=curr->right;
            }
        }
        return res;
        
    }
};