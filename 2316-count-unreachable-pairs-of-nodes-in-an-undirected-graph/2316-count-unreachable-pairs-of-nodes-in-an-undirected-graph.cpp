class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<long long int> res;
        unordered_map<int,vector<int>> ump;
        for(int i=0;i<edges.size();i++)
        {
            ump[edges[i][0]].push_back(edges[i][1]);
            ump[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            long long int count=0;
            if(!vis[i])
            {
                dfs(i,vis,ump,count);
            }
            res.push_back(count);
        }
        long long int p=n;
        long long int ans=(p*(p-1))/2;
        int sz=res.size();
        for(int i=0;i<sz;i++)
        {
            ans-=(res[i]*(res[i]-1)/2);
        }
        return ans;
    }
    void dfs(int s,vector<bool> &vis,unordered_map<int,vector<int>> &ump,long long int &count)
    {
        vis[s]=true;
        count++;
        for(auto x:ump[s])
        {
            if(!vis[x])
            dfs(x,vis,ump,count);
        }
    }
};