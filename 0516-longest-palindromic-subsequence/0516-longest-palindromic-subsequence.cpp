class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return recurse(s,0,s.length()-1,dp);
    }
    int recurse(string &s,int i, int j,vector<vector<int>> &dp)
    {
        if(j<i) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j])
        {
            return dp[i][j] = 2+recurse(s,i+1,j-1,dp);
        }
        return dp[i][j] = max(recurse(s,i+1,j,dp),recurse(s,i,j-1,dp));
    }
};