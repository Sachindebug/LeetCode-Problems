class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return recurse(word1,word2,word1.length()-1,word2.length()-1,dp);
    }
    int recurse(string &s1,string &s2,int i, int j,vector<vector<int>> &dp)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j])
        {
            return dp[i][j]=recurse(s1,s2,i-1,j-1,dp);
        }
        return dp[i][j]=min({
            1+recurse(s1,s2,i-1,j,dp),
            1+recurse(s1,s2,i-1,j-1,dp),
            1+recurse(s1,s2,i,j-1,dp)
        });
    }
};