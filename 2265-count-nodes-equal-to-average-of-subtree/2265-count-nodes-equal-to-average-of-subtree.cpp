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
    int averageOfSubtree(TreeNode* root) {
        recurse(root);
        return ans;
    }
    pair<int,int> recurse(TreeNode* root)
    {
        if(!root)
        {
            return {0,0};
        }
        pair<int,int> l = recurse(root->left);
        pair<int,int> r = recurse(root->right);
        int count1 = l.first;
        int sum1 = l.second;
        int count2 = r.first;
        int sum2 = r.second;
        int sum = sum1+sum2+root->val;
        int count = count1+count2+1;
        if((sum/count)==root->val) ans++;
        return {count,sum};
        
    }
};