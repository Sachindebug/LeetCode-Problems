class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,path(i,j,-1,matrix,dp));
            }
        }
        return ans;
    }
    int path(int i,int j,int prev,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]<=prev) return 0;
        if(dp[i][j]) return dp[i][j];
        return dp[i][j]=1+max({
                                path(i-1,j,matrix[i][j],matrix,dp),
                                path(i,j-1,matrix[i][j],matrix,dp),
                                path(i+1,j,matrix[i][j],matrix,dp),
                                path(i,j+1,matrix[i][j],matrix,dp)
        });
    }
};