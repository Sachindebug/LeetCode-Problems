class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        int n = grid2.size();
        int m = grid2[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<grid2.size();i++){
            for(int j = 0;j<grid2[i].size();j++){
                if(grid2[i][j] && grid1[i][j] && !vis[i][j]){
                    bool isValid = true;
                    dfs(grid1,grid2,vis,i,j,isValid);
                    if(isValid) count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>& vis, int i, int j, bool &isValid){
        int n = grid2.size();
        int m = grid2[0].size();
        vis[i][j]=1;
        if(i+1<n && !vis[i+1][j] && grid2[i+1][j]) {
            if(!grid1[i+1][j]) isValid = false;
            dfs(grid1,grid2,vis,i+1,j,isValid);
        }
        if(j+1<m && !vis[i][j+1] && grid2[i][j+1]) {
            if(!grid1[i][j+1]) isValid = false;
            dfs(grid1,grid2,vis,i,j+1,isValid);
        }
        if(i>0 && !vis[i-1][j] && grid2[i-1][j]) {
            if(!grid1[i-1][j]) isValid = false;
            dfs(grid1,grid2,vis,i-1,j,isValid);
        }
        if(j>0 && !vis[i][j-1] && grid2[i][j-1]) {
            if(!grid1[i][j-1]) isValid = false;
            dfs(grid1,grid2,vis,i,j-1,isValid);
        }
    }
};