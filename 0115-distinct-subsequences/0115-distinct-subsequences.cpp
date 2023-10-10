class Solution {
public:
    int f(int n, int m, string& s, string& t, vector<vector<int>>& dp){
         if(m<0)
            return 1;
        if(n<0)
            return 0;
       
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(s[n]==t[m]){
            return dp[n][m]=f(n-1,m-1,s,t,dp) + f(n-1,m,s,t,dp);
        }
        else
        {
            return dp[n][m]=f(n-1,m,s,t,dp);
        }
        
    }
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }
};