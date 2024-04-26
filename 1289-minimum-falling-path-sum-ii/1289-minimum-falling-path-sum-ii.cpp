class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1) return grid[0][0];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push({grid[0][i],i});
        }
        for(int i = 1;i<n;i++)
        {
            auto tp = pq.top();
            pq.pop();
            int mnidx1 = tp.second,mn1 = tp.first;
            auto tp2 = pq.top();
            pq = priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>();
            int mn2 = tp2.first;
            for(int j = 0;j<n;j++)
            {
                if(mnidx1!=j) grid[i][j]+=mn1;
                else grid[i][j]+=mn2;
                pq.push({grid[i][j],j});
            }
        }
        return *min_element(grid[n-1].begin(),grid[n-1].end());
    }
};