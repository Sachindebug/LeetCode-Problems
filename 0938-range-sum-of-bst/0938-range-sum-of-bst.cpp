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
    int preOrder(TreeNode* root,int low,int high)
    {
        int sum=0;
        if(root==NULL)
        {
            return 0;
        }
        TreeNode* temp=root;
        if((temp->val)>=low && (temp->val)<=high)
        {
            sum+=(temp->val);
        }
        int l=preOrder(root->left,low,high);
        int r=preOrder(root->right,low,high);
        return sum+l+r;
        
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return preOrder(root,low,high);
        
        
        
        
    }
};