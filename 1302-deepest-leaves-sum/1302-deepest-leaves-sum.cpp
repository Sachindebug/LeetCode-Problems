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
    int deepestLeavesSum(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        while(!q.empty())
        {
            temp.clear();
            int l=q.size();
            for(int i=0;i<l;i++)
            {
                TreeNode* t=q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                temp.push_back(t->val);
                
            }
        }
        int sum=0;
        for(auto x:temp)
        {
            sum+=x;
        }
        return sum;
    }
};