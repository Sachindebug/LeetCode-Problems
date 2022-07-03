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
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> temp;
        int sum=0;
        recurse(root,res,temp,0,target);
        return res;
    }
    void recurse(TreeNode* root,vector<vector<int>> &res, vector<int> &temp,int curr, int target)
    {
        if(!root) return;
        if(root && !root->left && !root->right)
        {
            if(curr+(root->val)==target)
            {
                temp.push_back(root->val);
                res.push_back(temp);
                temp.pop_back();
            }
            return;
            
        }
        temp.push_back(root->val);
        recurse(root->left,res,temp,curr+root->val,target);
        recurse(root->right,res,temp,curr+root->val,target);
        temp.pop_back();
        
    }
};