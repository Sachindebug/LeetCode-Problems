class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> queue;
        TreeNode* current = root;
        queue.push(current);
        bool even = true;
        while (!queue.empty()) {
            int size = queue.size();
            int prev = INT_MAX;
            if (even) {
                prev = INT_MIN;
            }
            while (size > 0) {
                current = queue.front();
                queue.pop();
                if ((even && (current->val % 2 == 0 || current->val <= prev)) || 
                        (!even && (current->val % 2 == 1 || current->val >= prev))) {
                    return false;
                }
                prev = current->val;
                if (current->left) {
                    queue.push(current->left);
                }
                if (current->right) {
                    queue.push(current->right);
                }
                size--;
            }
            even = !even;
        }
        return true;
    }
};