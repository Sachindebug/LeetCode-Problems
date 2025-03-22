class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                int componentSize = 0;
                int edgeCount = 0;
                dfs(adj,i,vis,componentSize,edgeCount);
                count+=((componentSize*(componentSize-1))==edgeCount);
                cout<<componentSize<<" "<<edgeCount<<endl;
            }
        }
        return count;
    }
    void dfs(vector<vector<int>> &adj, int s, vector<int> &vis, int &componentSize, int &edgeCount){
        vis[s] = 1;
        bool valid = true;
        componentSize++;
        for(auto child: adj[s]){
            edgeCount++;
            if(!vis[child]){
                dfs(adj,child,vis,componentSize,edgeCount);
            }
        }
    }
};