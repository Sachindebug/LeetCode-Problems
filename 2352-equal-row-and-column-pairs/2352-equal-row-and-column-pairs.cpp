class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {   
                bool found=true;
                for(int k=0;k<n;k++)
                {
                    if(grid[k][j]!=grid[i][k]) found=false;
                }
                if(found) count++;
            }
            
        }
        return count;
        
    }
};