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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int res=1;
        int f,l;
        while(!q.empty())
        {
            int n=q.size();
            int mn=q.front().second;
            for(int i=0;i<n;i++)
            {
                long long int curr=q.front().second-mn;
                TreeNode* temp=q.front().first;
                q.pop();
                if(i==0) f=curr;
                if(i==n-1) l=curr;
                if(temp->left) q.push({temp->left,curr*2+1});
                if(temp->right) q.push({temp->right,curr*2+2});

            }
            res=max(res,l-f+1);
            
        }
        return res;
    }
};