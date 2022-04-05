class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<d.size();i++)
        {
            graph[d[i][0]].push_back(d[i][1]);
            graph[d[i][1]].push_back(d[i][0]);

        }
    
        vector<int> colors(n+1, 0);
        queue<int> q;
        
        for (int i = 1; i <= n; i++) {
            if (colors[i]) continue;
            
            colors[i] = 1;
            q.push(i);
            
            while (!q.empty()) {
                int temp = q.front();
                
                for (auto neighbor : graph[temp]) {
                    
					// Color neighbor with opposite color
                    if (!colors[neighbor]){
                        colors[neighbor] = -colors[temp];
                        q.push(neighbor);
                    }
                    
					// If the neighbor has the same color - can't bipartite.
                    else if (colors[neighbor] == colors[temp]) 
                        return false;
                }
                q.pop();
            }
        }
        return true;
    }
};