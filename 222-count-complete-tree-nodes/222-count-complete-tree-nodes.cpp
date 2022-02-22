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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int l=leftHeight(root);
        int r=rightHeight(root);
        if(l==r) return (1<<l)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int leftHeight(TreeNode* root)
    {
        int res=0;
        while(root)
        {
            res++;
            root=root->left;
        }
        return res;
    }
    int rightHeight(TreeNode* root)
    {
        int res=0;
        while(root)
        {
            res++;
            root=root->right;
        }
        return res;
    }
};