class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    
                    int res=dfsislands(grid,i,j);
                    count=max(res,count);
                }
            }
        }
        return count;
    }
    int  dfsislands(vector<vector<int>>& grid, int i, int j)
    {
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1)
        {
            return 0;
        }
        
        grid[i][j]=0;
        
        return 1+dfsislands(grid,i+1,j)+dfsislands(grid,i,j+1)+dfsislands(grid,i-1,j)+dfsislands(grid,i,j-1);
    }
    
   
    
};