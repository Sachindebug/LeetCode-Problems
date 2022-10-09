class Solution {
public:
    int numberOfPaths(vector<vector<int>>& g, int k) {
        int n=g.size();
        int m=g[0].size();
        int MOD=1e9+7;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,0)));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int kk=0;kk<k;kk++)
                {
                    dp[i][j][kk]=0;
                    g[i][j]%=k;  
                    
                    if(i==0&&j==0)
                    {
                          if(kk==g[i][j])
                          dp[i][j][kk]= 1;
                    }
                    else if(i==0)
                    {
                          int j1 = (kk-g[i][j]+k)%k;
						  
                         dp[i][j][kk]+=dp[i][j-1][j1]%MOD;
                         dp[i][j][kk]%=MOD;
                    }
                    else if(j==0)
                    {
                         int j1 = (kk-g[i][j]+k)%k;
						 
                         dp[i][j][kk]+=dp[i-1][j][j1]%MOD;
                         dp[i][j][kk]%=MOD;
                    }
                    else
                    {
                         int j1 = (kk-g[i][j]+k)%k;
                         
                         dp[i][j][kk]+=(dp[i][j-1][j1]+dp[i-1][j][j1])%MOD;
                         dp[i][j][kk]%=MOD;
                    }
                
                }
            }
            
        }
        return dp[n-1][m-1][0];
    }
};