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
    int sumNumbers(TreeNode* root) {
        long long int sum=0;
        return recurse(root,sum);
        
    }
    long long int recurse(TreeNode* root,long long int sum)
    {
        if(!root) return 0;
        sum=sum*10+(root->val);
        if(!root->left && !root->right) return sum;
        long long int p = recurse(root->left,sum);
        long long int q= recurse(root->right,sum);
        return p+q;

    }
        
};