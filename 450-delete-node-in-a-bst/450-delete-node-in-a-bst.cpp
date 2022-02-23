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
       TreeNode *curr=root;
        while(root!=nullptr)
        {
            if(root->val>key)
            {
                if(root->left!=nullptr && root->left->val==key)
                {
                    root->left=helper(root->left);
                    break;
                }
                else root=root->left;
            }
            else
            {
                if(root->right!=nullptr && root->right->val==key)
                {
                    root->right=helper(root->right);
                    break;
                }
                else root=root->right;
                
            }
        }
        return curr;
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