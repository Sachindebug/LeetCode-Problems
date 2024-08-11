class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj, int& cnt) {
        int size = 1;
        int fc = -1;
        bool isGood = true;
        
        for (int adjNode : adj[node]) {
            if (adjNode != parent) {
                int cs = dfs(adjNode, node, adj, cnt);
                size += cs;
                if (fc == -1) {
                    fc = cs;
                } else if (fc != cs) {
                    isGood = false;
                }
            }
        }
        if (isGood) {
            cnt++;
        }
        
        return size;
    }
    
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        int cnt = 0;
        
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        dfs(0, -1, adj, cnt);
        
        return cnt;
    }
};