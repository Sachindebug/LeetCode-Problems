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
private:
    int ans = 0;
public:
    int longestZigZag(TreeNode* root) {
        int l = recurse(root->left,1);
        int r = recurse(root->right,0);
        ans = max(ans,1+max(l,r));
        return ans;
    }
    int recurse(TreeNode* root, int dir){
        if(!root) return -1;
        int l = recurse(root->left,1);
        int r = recurse(root->right,0);
        ans = max(ans,1+max(l,r));
        if(dir) return 1+r;
        return 1+l;
    }
};