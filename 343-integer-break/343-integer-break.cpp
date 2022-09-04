class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        vector<int> dp(n+1,-1);
        return recurse(n,dp);
    }
    int recurse(int n,vector<int> &dp)
    {
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int pro=1;
        for(int i=1;i<=n;i++)
        {
            pro=max(pro,i*recurse(n-i,dp));
        }
        return dp[n]=pro;
    }
};