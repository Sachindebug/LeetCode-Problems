class Solution {
public:
    int mod=1e9+7;
    int numberOfWays(int s, int e, int k) {
        vector<vector<int>> dp(4001,vector<int> (1005,-1));
        return recurse(s,e,k,dp);
    }
    int recurse(int s,int e,int k,vector<vector<int>> &dp)
    {
        if(k==0) return s==e;
        if(dp[s+1000][k]!=-1) return dp[s+1000][k];
        return dp[s+1000][k]=(recurse(s+1,e,k-1,dp)%mod+recurse(s-1,e,k-1,dp)%mod)%mod;
    }
};