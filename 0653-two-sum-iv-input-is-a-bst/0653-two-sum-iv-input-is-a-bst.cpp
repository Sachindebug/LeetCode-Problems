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

class BSTIterator{
    stack<TreeNode*> st;
    TreeNode* node;
    bool forward;
public:
    BSTIterator(TreeNode* _root, bool _forward){
        node = _root,
        forward = _forward;
    }
    int next(){
        while (node || !st.empty()) {
            if (node) {
                st.push(node);
                node = forward ? node->left : node->right;
            }
            else {
                node = st.top();
                st.pop();
                int nextVal = node->val;
                node = forward ? node->right : node->left;
                return nextVal;
            }
        }
        return -1;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root,true);
        BSTIterator r(root,false);
        for(int i = l.next(), j=r.next(); i<j;){
            int sum = i + j;
            if (sum == k) {
                return true;
            }
            else if (sum < k) {
                i = l.next();
            }
            else {
                j = r.next();
            }
        }
        return false;
    }
};
