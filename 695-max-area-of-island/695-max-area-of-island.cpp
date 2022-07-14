class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int count=0;
        vector<vector<int>> seen(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] && !seen[i][j])
                {
                    int res=dfsislands(grid,i,j,seen);
                    count=max(res,count);
                }
            }
        }
        return count;
    }
    int  dfsislands(vector<vector<int>>& grid, int i, int j,vector<vector<int>>& seen)
    {
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || !grid[i][j] || seen[i][j])
        {
            return 0;
        }
        seen[i][j]=1;
        
        
        return 1+dfsislands(grid,i+1,j,seen)+dfsislands(grid,i,j+1,seen)+
                 dfsislands(grid,i-1,j,seen)+dfsislands(grid,i,j-1,seen);
    }
    
   
    
};