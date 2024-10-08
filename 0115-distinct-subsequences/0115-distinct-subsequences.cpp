class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long> (m+1,-1));
        for(int i = 0;i<=m;i++) dp[0][i] = 0;
        for(int j = 0;j<=n;j++) dp[j][0] = 1;
        for(int i = 1;i<=n;i++){
            for(int j =1;j<=m;j++){
                dp[i][j] = dp[i-1][j];
                if(s[i-1]==t[j-1]) dp[i][j]+=dp[i-1][j-1];
            }
        }
        return dp[n][m];
    }
};