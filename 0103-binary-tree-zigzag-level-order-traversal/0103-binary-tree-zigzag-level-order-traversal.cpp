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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)
        {
            return res;
        }
        bool turn=true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int level=q.size();
            vector<int> t;
            for(int i=0;i<level;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                t.push_back(temp->val);
                
            }
            if(!turn)
            {
                reverse(t.begin(),t.end());
            }
            turn=!turn;
            res.push_back(t);
        }
        return res;
        
    }
};