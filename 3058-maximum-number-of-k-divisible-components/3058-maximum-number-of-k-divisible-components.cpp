class Solution {
public:
    int count = 0;
    long long dfs(map<int,vector<int>> &ump,vector<int> &vis,int s,int k,vector<int>& values)
    {
        vis[s]=1;
        long long sum = values[s];
        for(auto x:ump[s])
        {
            if(!vis[x])
            {
                sum += (1ll*dfs(ump,vis,x,k,values));
            }
        }
        if(sum%k==0) 
        {
            count+=1;
            return 0;
        }
        return sum;
        
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if(n==1)
        {
            if(values[0]%k==0) return 1;
            return 0;
        }
        map<int,vector<int>> ump;
        for(auto x:edges)
        {
            int a = x[0];
            int b = x[1];
            ump[a].push_back(b);
            ump[b].push_back(a);
        }
        vector<int> vis(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(ump,vis,i,k,values);
        }
        return count;
    }
};