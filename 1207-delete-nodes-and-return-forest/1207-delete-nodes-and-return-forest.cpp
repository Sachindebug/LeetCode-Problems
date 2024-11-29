class Solution {
public:
    vector<TreeNode*> res;
    TreeNode* dfs(TreeNode* root, unordered_set<int>& s) {
        if (!root) return nullptr;  
        root->left = dfs(root->left, s);
        root->right = dfs(root->right, s);
        if (s.count(root->val)) {
            if (root->left) res.push_back(root->left);
            if (root->right) res.push_back(root->right);
            return nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        if (!s.count(root->val)) {
            res.push_back(root);
        }
        dfs(root, s);
        return res;
    }
};