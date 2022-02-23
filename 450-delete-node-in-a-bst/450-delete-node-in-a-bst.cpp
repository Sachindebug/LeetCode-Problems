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
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(!root) return nullptr;
       if (root->val==key)
       {
           return helper(root);
       }
      if(root->val>key)
      {
          root->left=deleteNode(root->left,key);      
      }
      else
      {
          root->right=deleteNode(root->right,key);      
     
      }
      return root;
    }
    TreeNode* helper(TreeNode* root)
    {
        if(!root->left) return root->right;
        else if(!root->right) return root->left;
        TreeNode* rc=root->right;
        TreeNode* lrc=find(root->left);
        lrc->right=rc;
        return root->left;
    }
    TreeNode* find(TreeNode* root)
    {
        if(root->right==nullptr)
        {
            return root;
        }
        return find(root->right);
    }
};