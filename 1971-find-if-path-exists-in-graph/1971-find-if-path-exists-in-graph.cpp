class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto x:edges)
        {
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        dfs(adj,vis,source);
        return vis[destination];
    }
    void dfs(vector<vector<int>> &adj,vector<int> &vis,int s)
    {
        vis[s]=1;
        for(auto x:adj[s])
        {
            if(!vis[x])
            {
                dfs(adj,vis,x);
            }
        }
    }
};