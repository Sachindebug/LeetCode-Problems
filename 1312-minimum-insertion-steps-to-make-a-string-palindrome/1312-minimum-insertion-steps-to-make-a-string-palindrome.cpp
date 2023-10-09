class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return recurse(s,0,s.length()-1,dp);
    }
    int recurse(string &s, int i,int j, vector<vector<int>> &dp)
    {
        if(j<=i) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res = 500;
        if(s[i]==s[j]) res = recurse(s,i+1,j-1,dp);
        res=min({res,1+recurse(s,i,j-1,dp),1+recurse(s,i+1,j,dp)});
        
        return dp[i][j]=res;
    }
};