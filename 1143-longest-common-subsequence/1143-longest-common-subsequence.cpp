class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(1001,vector<int> (1001,-1));
        return myfun(text1,text2,text1.length(),text2.length(),dp);
    }
    
    int myfun(string &s1,string &s2,int i,int j,vector<vector<int>> &dp)
    {
        
        if(i==0 || j==0)
        {
            dp[i][j]=0;
            return 0;
        }
       if(dp[i-1][j-1]!=-1) return dp[i-1][j-1];
        if(s1[i-1]==s2[j-1])
        {
            dp[i-1][j-1]=1+myfun(s1,s2,i-1,j-1,dp);
            return dp[i-1][j-1];
        }
        else
        {
            dp[i-1][j-1]=max(myfun(s1,s2,i-1,j,dp),myfun(s1,s2,i,j-1,dp));
            return dp[i-1][j-1];
        }
    }
};