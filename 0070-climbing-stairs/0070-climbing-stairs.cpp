class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return recurse(n,dp);
    }
    int recurse(int n,vector<int> &dp)
    {
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=recurse(n-1,dp)+recurse(n-2,dp);
    }
};