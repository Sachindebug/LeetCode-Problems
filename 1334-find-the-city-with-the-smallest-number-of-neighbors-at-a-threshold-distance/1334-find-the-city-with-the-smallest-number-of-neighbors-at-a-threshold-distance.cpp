class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=1e8;
        for(int i=0;i<n;i++)
            dp[i][i] = 0;
        for(auto x:edges)
        {
            int u = x[0],v = x[1], w = x[2];
            dp[u][v] = w;
            dp[v][u] = w;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    dp[j][k] = min(dp[j][k],dp[j][i]+dp[i][k]);
                }
            }
        }
        int ans = n+1;
        int res = -1;
        for(int i = 0;i<n;i++)
        {
            int count = 0;
            for(int j = 0;j<n;j++)
            {
                if(dp[i][j]<=d) count++;
            }
            if(count<=ans) 
            {
                ans = count;
                res = i;
            }
        }
        return res;
    }
};