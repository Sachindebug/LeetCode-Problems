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
    void addRow(TreeNode* root, int val, int currDepth, int depth)
    {
        if(!root) return;
        
        if(currDepth == depth - 1)
        {
            TreeNode* currLeft = root->left;
            TreeNode* currRight = root->right;
            
            root->left = new TreeNode(val, currLeft, NULL);
            root->right = new TreeNode(val, NULL, currRight);
        }
        
        addRow(root->left, val, currDepth + 1, depth);
        addRow(root->right, val, currDepth + 1, depth);
        
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(depth == 1)
        {
            TreeNode *newRoot = new TreeNode(val, root, NULL);
            
            return newRoot;
        }
        
        addRow(root, val, 1, depth);
        
        return root;
    }
};