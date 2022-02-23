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
        if(preorder.size()==0) return nullptr;
        if(preorder.size()==1) return new TreeNode(preorder[0]);
        vector<int> p1;
        vector<int> p2;
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++)
        {
            if(preorder[i]>preorder[0]) p2.push_back(preorder[i]);
            else p1.push_back(preorder[i]);
        }
        root->left=bstFromPreorder(p1);
        root->right=bstFromPreorder(p2);
        return root;
    }

};