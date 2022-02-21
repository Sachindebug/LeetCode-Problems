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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        if(n==0) return nullptr;
        TreeNode *root=new TreeNode(postorder[n-1]);
        if(n==1)
        {
            return root;
        }
        int idx=0;
        int x=postorder[n-1];
        for(int i=0;i<n;i++)
        {
            if(inorder[i]==x)
            {
                idx=i;
                break;
            }
        }
        vector<int> p1;
        vector<int> i1;
        vector<int> p2;
        vector<int> i2;
        
        for(int i=0;i<idx;i++)
        {
            i1.push_back(inorder[i]);
        }
        for(int i=idx+1;i<n;i++)
        {
            i2.push_back(inorder[i]);
        }
        int sz=i1.size();
        for(int i=0;i<sz && i<n;i++)
        {
            p1.push_back(postorder[i]);
        }
        for(int i=sz;i<n-1;i++)
        {
            p2.push_back(postorder[i]);
        }
        root->left=buildTree(i1,p1);
        root->right=buildTree(i2,p2);
        return root;
    }
};