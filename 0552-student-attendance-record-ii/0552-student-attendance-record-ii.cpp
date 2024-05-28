class Solution {
public:
    int MOD = 1000000007;
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return recurse(n,0,0,dp);
    }
    int recurse(int n,int a,int l,vector<vector<vector<int>>> &dp)
    {
        if(a>=2 || l>=3) return 0;
        if(n==0) return 1;
        if(dp[n][a][l]!=-1) return dp[n][a][l];
        int res = 0;
        res+=recurse(n-1,a,0,dp);
        res%=MOD;
        res+=recurse(n-1,a+1,0,dp);
        res%=MOD;
        res+=recurse(n-1,a,l+1,dp);
        res%=MOD;
        return dp[n][a][l] = res;
    }
};