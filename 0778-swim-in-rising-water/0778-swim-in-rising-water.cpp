class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l=0;
        int r=n*n;
        int res = -1;
        while(l<=r)
        {
            int m = l+(r-l)/2;
            if(isPossible(grid,m))
            {
                res = m;
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return res;
    }
    bool isPossible(vector<vector<int>>& grid, int m)
    {
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(grid[0][0]>m) return false;
        dfs(grid,vis,0,0,m);
        return vis[n-1][n-1]==1;
    }
    void dfs(vector<vector<int>>& grid,vector<vector<int>> &vis, int i, int j, int m)
    {
        vis[i][j] = 1;
        int n = grid.size();
        if(i+1<n && !vis[i+1][j] && grid[i+1][j]<=m) dfs(grid,vis,i+1,j,m);
        if(i>0 && !vis[i-1][j] && grid[i-1][j]<=m) dfs(grid,vis,i-1,j,m);
        if(j+1<n && !vis[i][j+1] && grid[i][j+1]<=m) dfs(grid,vis,i,j+1,m);
        if(j>0 && !vis[i][j-1] && grid[i][j-1]<=m) dfs(grid,vis,i,j-1,m);
    }
};