class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        int x= entrance[0];
        int y= entrance[1];
        bfs(maze,x,y,dis);
        int res=INT_MAX;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0 || i==m-1 || j==n-1)
                {
                    if(i!=x || y!=j)
                    res=min(res,dis[i][j]);
                }
            }
        }
        if(res==INT_MAX) return -1;
        return res;

    }
    void bfs(vector<vector<char>>& maze,int x,int y,vector<vector<int>>& dis)
    {
        dis[x][y]=0;
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<bool>> vis(m+1,vector<bool>(n+1,false));
        queue<pair<int,int>> q;
        vis[x][y]=true;
        q.push({x,y});
        while(!q.empty())
        {
            auto p = q.front();
            int i=p.first;
            int j=p.second;
            q.pop();
            
            if(i<m-1 && maze[i+1][j]=='.' && !vis[i+1][j])
            {
                vis[i+1][j]=true;
                dis[i+1][j]=dis[i][j]+1;
                q.push({i+1,j});
            }
            if(j<n-1 && maze[i][j+1]=='.' && !vis[i][j+1])
            {
                vis[i][j+1]=true;
                dis[i][j+1]=dis[i][j]+1;
                q.push({i,j+1});
            }
            if(i>0 && maze[i-1][j]=='.' && !vis[i-1][j])
            {
                vis[i-1][j]=true;
                dis[i-1][j]=dis[i][j]+1;
                q.push({i-1,j});
            }
            if(j>0 && maze[i][j-1]=='.' && !vis[i][j-1])
            {
                vis[i][j-1]=true;
                dis[i][j-1]=dis[i][j]+1;
                q.push({i,j-1});
            }
        }
    }
};