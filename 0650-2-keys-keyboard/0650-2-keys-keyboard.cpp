class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return 1+recurse(1,1,n,dp);
    }
    int recurse(int added, int cop,int n,vector<vector<int>> &dp){
        if(added>n) return 1000;
        else if(added==n) return 0;
        if(dp[added][cop]!=-1) return dp[added][cop];
        return dp[added][cop] = min(1+recurse(added+cop,cop,n,dp),2+recurse(added*2,added,n,dp));
    }
};