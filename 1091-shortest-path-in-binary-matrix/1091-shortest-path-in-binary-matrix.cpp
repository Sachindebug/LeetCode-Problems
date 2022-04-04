class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1) return -1;
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        vector<vector<int>> dis(n,vector<int>(n,0));
        vis[0][0]=true;
        q.push({0,0});
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            int i=x.first;
            int j=x.second;
            if(i<n-1 && grid[i+1][j]==0 && !vis[i+1][j])
            {
                vis[i+1][j]=true;
                dis[i+1][j]=dis[i][j]+1;
                q.push({i+1,j});
            }
            if(j<n-1 && grid[i][j+1]==0 && !vis[i][j+1])
            {
                vis[i][j+1]=true;
                dis[i][j+1]=dis[i][j]+1;
                q.push({i,j+1});
            }
            if(i>0 && grid[i-1][j]==0 && !vis[i-1][j])
            {
                vis[i-1][j]=true;
                dis[i-1][j]=dis[i][j]+1;
                q.push({i-1,j});
            }
            if(j>0 && grid[i][j-1]==0 && !vis[i][j-1])
            {
                vis[i][j-1]=true;
                dis[i][j-1]=dis[i][j]+1;
                q.push({i,j-1});
            }
            if(i<n-1 && j>0 && grid[i+1][j-1]==0 && !vis[i+1][j-1])
            {
                vis[i+1][j-1]=true;
                dis[i+1][j-1]=dis[i][j]+1;
                q.push({i+1,j-1});
            }
            if(j<n-1 && i<n-1 && grid[i+1][j+1]==0 && !vis[i+1][j+1])
            {
                vis[i+1][j+1]=true;
                dis[i+1][j+1]=dis[i][j]+1;
                q.push({i+1,j+1});
            }
            if(i>0 &&  j>0 && grid[i-1][j-1]==0 && !vis[i-1][j-1])
            {
                vis[i-1][j-1]=true;
                dis[i-1][j-1]=dis[i][j]+1;
                q.push({i-1,j-1});
            }
            if(i>0 && j<n-1 && grid[i-1][j+1]==0 && !vis[i-1][j+1])
            {
                vis[i-1][j+1]=true;
                dis[i-1][j+1]=dis[i][j]+1;
                q.push({i-1,j+1});
            }
            
            
        }
        if(!vis[n-1][n-1]) return -1;
        return dis[n-1][n-1]+1;
    }
};