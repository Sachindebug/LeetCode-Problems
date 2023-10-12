class Solution {
public:
    bool Allstars(int n, string &s){
        for(int i=n; i>=0; i--){
            if(s[i]!='*')
                return 0;
        }
        return 1;
    }
    bool f(int n, int m, string& s, string& p, vector<vector<int>>& dp){
        if(n<0 && m<0)
            return 1;
        if(n<0 && m>=0)
            return 0;
        if(n>=0 && m<0)
            return Allstars(n,p);
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(p[n]==s[m] || p[n]=='?')
            return dp[n][m]= f(n-1,m-1,s,p,dp);
        if(p[n]=='*')
            return dp[n][m]= f(n-1,m,s,p,dp) || f(n,m-1,s,p,dp);
        else
            return dp[n][m]=0;
    }
    bool isMatch(string s, string p) {
        int n=p.size(), m=s.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return f(n-1,m-1,s,p,dp);
    }
};