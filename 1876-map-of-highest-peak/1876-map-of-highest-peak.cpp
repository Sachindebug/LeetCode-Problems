class Solution {
public:
        vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size(), dir[5] = {0, 1, 0, -1, 0}, INF = 1e6+1;
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(isWater[i][j]) {
                    isWater[i][j]=0;
                    q.push({i, j});
                } else {
                    isWater[i][j]=INF;
                }
            }
        }
        int height = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto cur = q.front(); q.pop();
                for(int i=0; i<4; i++) {
                    int r = cur.first + dir[i], c = cur.second + dir[i+1];
                    if(r < 0 || c < 0 || r >= m || c >= n) {
                        continue;
                    }
                    if(height < isWater[r][c]) {
                        isWater[r][c] = height;
                        q.push({r,c});
                    }
                }
            }
            height++;
        }
        return isWater;
    }
};