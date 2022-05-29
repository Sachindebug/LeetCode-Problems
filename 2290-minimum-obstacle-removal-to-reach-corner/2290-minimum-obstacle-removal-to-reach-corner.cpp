class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int  m = grid.size();
       int n = grid[0].size();
       
        int vis[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++) vis[i][j] =-1;
        }
        // Creating a Deque since we need double sided insertion
        deque<pair<int,pair<int,int>>> q;
        q.push_front({0,{0,0}});
        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};
        while(!q.empty())
        {
            pair<int,pair<int,int>> p =q.front(); q.pop_front();
            
            if(p.second.first == m-1 && p.second.second == n-1)
            {
               return p.first; 
              
            }
            
            int x=p.second.first; int y=p.second.second;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(nx>=0 && nx<m && ny>=0 && ny< n)
                {
				// if the cell is empty
                    if(grid[nx][ny] == 0  && (vis[nx][ny]==-1 || vis[nx][ny] > p.first))
                    {
                        q.push_front({p.first,{nx,ny}});
                        vis[nx][ny]=p.first;
                    }
					// if cell has obstacle we will need to add 1 to answer.
                    else if(grid[nx][ny] ==1 && ((vis[nx][ny]==-1 || vis[nx][ny] > p.first+1)))
                    {
                        q.push_back({p.first+1,{nx,ny}});
                        vis[nx][ny]=p.first+1;
                    }
                }
            }
             
        }
        return -1;
    }
};