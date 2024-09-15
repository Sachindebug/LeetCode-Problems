class Solution {
public:
    long long np = -50000000000;
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n =b.size();
        vector<vector<long long>> dp(4,vector<long long>(n,np));
        return recurse(a,b,0,0,dp);
    }
    long long recurse(vector<int>& a, vector<int>& b, int i, int j,vector<vector<long long>> &dp){
        if(i==4) return 0;
        if(j==b.size()){
            return np;
        }
        if(dp[i][j]!=np) return dp[i][j];
        return dp[i][j] = max(1ll*a[i]*b[j]+recurse(a,b,i+1,j+1,dp),recurse(a,b,i,j+1,dp));
    }
};