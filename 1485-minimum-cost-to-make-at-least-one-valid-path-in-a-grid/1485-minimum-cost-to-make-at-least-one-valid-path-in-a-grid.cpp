class Solution {
public:
    #define F first
    #define S second
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int dist[n][m];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                dist[i][j] = 1e9;
            }
        }
        deque<pair<int, int>> pq;
        pq.push_back({0, 0});
        dist[0][0] = 0;
        while(!pq.empty()){
            auto cur = pq.front();
            pq.pop_front();
            int cur_x = cur.F;
            int cur_y = cur.S;
            int weight = grid[cur_x][cur_y];
            for(int i = 0; i<4; i++){
                int x = cur_x + dx[i];
                int y = cur_y + dy[i];
                int val = 1;
                if(i + 1 == weight){
                    val = 0;
                }
                if(x <n && y<m && x>=0 && y>=0){// valid thingy
                    if(dist[x][y] > dist[cur_x][cur_y] + val){
                        dist[x][y] = dist[cur_x][cur_y] + val;
                        if(val){
                            pq.push_back({x, y});
                        }else{
                            pq.push_front({x, y});
                        }
                       
                    }
                }
            }
            
        }
        return dist[n -1][m - 1];
    }
};