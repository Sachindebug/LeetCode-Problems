class Solution {
public:
    void dfs(map<int,vector<int>> &adj,int s,vector<int> &vis)
    {
        vis[s]=1;
        for(auto x:adj[s])
        {
            if(!vis[x])
            {
                dfs(adj,x,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        map<int,vector<int>> adj;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr.size();j++)
            {
                if(i!=j && arr[i][j]==1)
                {
                    adj[i].push_back(j);
                }
            }
        }
        int n=arr.size();
        int count=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(adj,i,vis);
            }
        }
        return count;
    }
};