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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int m=*max_element(nums.begin(),nums.end());
        TreeNode* root=new TreeNode(m);
        int idx=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==m) idx=i;
        }
        root->left=recurse(nums,0,idx);
        root->right=recurse(nums,idx+1,nums.size());
        return root;
    }
    TreeNode* recurse(vector<int> &nums,int l,int r)
    {
        if(l>=r)
        {
            return NULL;
        }
        int m=INT_MIN;
        int idx=-1;
        for(int i=l;i<r;i++)
        {
            if(nums[i]>m)
            {
                m=nums[i];
                idx=i;
            }
        }
        TreeNode* root=new TreeNode(m);
        root->left=recurse(nums,l,idx);
        root->right=recurse(nums,idx+1,r);
        return root;
    }
};