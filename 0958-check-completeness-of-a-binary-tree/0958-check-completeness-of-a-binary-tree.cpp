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
    bool checkForAllNull(queue<TreeNode*> q){
        while(!q.empty()){
            if(q.front() !=NULL)
                return false;
            q.pop();
        }
        return true;
    }
    
    bool isCompleteTree(TreeNode* root) {
        int i,j,h=0;
        queue<TreeNode*> q;
        TreeNode *p;
        q.push(root);
        while(!q.empty()){
            p = q.front();
            if(p==NULL){ 
                if(checkForAllNull(q))
                    return true;
                return false;
            }
            q.push(p->left);
            q.push(p->right);
            q.pop();
        }
        return true;
    }
};