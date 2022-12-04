class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int res=INT_MAX;
        unordered_map<int,vector<pair<int,int>>> ump;
        for(auto x:roads)
        {
            int u=x[0];
            int v=x[1];
            int w=x[2];
            ump[u].push_back({v,w});
            ump[v].push_back({u,w});
        }
        unordered_map<int,int> vis;
        dfs(ump,vis,res,1);
        return res;
    }
    void dfs(unordered_map<int,vector<pair<int,int>>> &ump,unordered_map<int,int> &vis,int &res,int s)
    {
        vis[s]=1;
        for(auto x:ump[s])
        {
            res=min(res,x.second);
            if(!vis[x.first])
            {
                
                dfs(ump,vis,res,x.first);
            }
        }
    }
};