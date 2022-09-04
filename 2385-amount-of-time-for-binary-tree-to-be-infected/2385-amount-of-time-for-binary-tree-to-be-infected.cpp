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
    int amountOfTime(TreeNode* root, int s) {
        unordered_map<int,vector<int>> adj;
        dfs(root,adj);
        unordered_map<int,int> dis;
        unordered_map<int,bool> vis;
        queue<int> q;
        q.push(s);
        dis[s]=0;
        vis[s]=true;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(auto y:adj[x])
            {
                if(vis.find(y)==vis.end())
                {
                    vis[y]=true;
                    q.push(y);
                    dis[y]=dis[x]+1;
                }
            }
        }
        int res=0;
        for(auto x:dis)
        {
            res=max(res,x.second);
        }
        return res;
    }
    void dfs(TreeNode* root,unordered_map<int,vector<int>> &ump)
    {
        if(!root) return;
        if(root->left) 
        {
            ump[root->val].push_back(root->left->val);
            ump[root->left->val].push_back(root->val);

        }
        if(root->right) 
        {
            ump[root->val].push_back(root->right->val);
            ump[root->right->val].push_back(root->val);
        }
        dfs(root->left,ump);
        dfs(root->right,ump);
    }
};