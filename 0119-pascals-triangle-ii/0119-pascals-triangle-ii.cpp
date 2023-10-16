class Solution {
public:
    int f(int r, int c, vector<vector<int>>& dp){
        if(r<0 || c<0)
            return 0;
        if(c==0 || r==c)
            return 1;
        if(dp[r][c]!=0)
            return dp[r][c];
        return dp[r][c]= f(r-1,c-1,dp) + f(r-1,c,dp);
    }
    vector<int> getRow(int r) {
        vector<vector<int>>dp(r+1, vector<int>(r+1,0));
        for(int i=1; i<r; i++){
            dp[r][i]= f(r,i,dp);
        }
        dp[r][0]=1;
        dp[r][r]=1;
        return dp[r];
    }
};