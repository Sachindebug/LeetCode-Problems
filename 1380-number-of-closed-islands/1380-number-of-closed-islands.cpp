class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!grid[i][j] && !vis[i][j]){
                    bool nonBoundary = true;
                    dfs(grid,vis,i,j,nonBoundary);
                    if(nonBoundary) count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis, int row, int col, bool &cond){
        int n = grid.size();
        int m = grid[0].size();
        if(row<0 || col<0 || row>=n || col>=m) {
            cond = false;
            return;
        }
        if(grid[row][col]==1 || vis[row][col]) return;
        vis[row][col] = 1;
        vector<int> dir = {-1,0,1,0,-1};
        for(int i = 0; i < 4; i++){
            int newRow = row + dir[i];
            int newCol = col + dir[i+1];
            dfs(grid,vis,newRow,newCol,cond);
        }
    }
};