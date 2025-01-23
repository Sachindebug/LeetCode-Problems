class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int> rows;
        unordered_map<int,int> coloums;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    rows[i]++;
                    coloums[j]++;
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    if(rows[i]>=2 || coloums[j]>=2) count++;
                }
            }
        }
        return count;
        
    }
};