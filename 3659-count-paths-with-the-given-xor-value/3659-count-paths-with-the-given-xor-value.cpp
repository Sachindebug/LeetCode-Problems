class Solution {
private:
    int mod = 1000000007;
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(16,-1)));
        return recurse(grid,0,0,k,0,dp);
    }
    int recurse(vector<vector<int>>& grid, int i, int j, int k, int curr, vector<vector<vector<int>>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return 0;
        if(dp[i][j][curr]!=-1) return dp[i][j][curr];
        if(i==n-1 && j==m-1){
            if((curr^grid[i][j])==k) return 1;
            return 0;
        }
        dp[i][j][curr] = recurse(grid,i+1,j,k,curr^grid[i][j],dp) + recurse(grid,i,j+1,k,curr^grid[i][j],dp);
        dp[i][j][curr]%=mod;
        return dp[i][j][curr];
    }
};