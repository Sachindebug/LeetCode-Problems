class Solution {
private:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int i, int j)
    {
        vis[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();
        if(i+1<n && grid[i+1][j]=='1' && !vis[i+1][j]) dfs(grid,vis,i+1,j); 
        if(i>0 && grid[i-1][j]=='1' && !vis[i-1][j]) dfs(grid,vis,i-1,j); 
        if(j+1<m && grid[i][j+1]=='1' && !vis[i][j+1]) dfs(grid,vis,i,j+1); 
        if(j>0 && grid[i][j-1]=='1' && !vis[i][j-1]) dfs(grid,vis,i,j-1); 
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    dfs(grid,vis,i,j);
                    res++;
                }
            }
        }
        return res;
    }
};