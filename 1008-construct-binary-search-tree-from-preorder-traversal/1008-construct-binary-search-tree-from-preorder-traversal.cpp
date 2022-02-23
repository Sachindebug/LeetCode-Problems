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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        return buildTree(preorder,inorder);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        if(n==0) return nullptr;
        TreeNode *root=new TreeNode(preorder[0]);
        if(n==1)
        {
            return root;
        }
        int idx=0;
        int x=preorder[0];
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
        for(int i=1;i<n && i<=sz;i++)
        {
            p1.push_back(preorder[i]);
        }
        for(int i=sz+1;i<n;i++)
        {
            p2.push_back(preorder[i]);
        }
        root->left=buildTree(p1,i1);
        root->right=buildTree(p2,i2);
        return root;
    }
};