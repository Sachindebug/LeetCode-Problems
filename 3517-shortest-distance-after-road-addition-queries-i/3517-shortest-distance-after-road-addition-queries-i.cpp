class Solution {
private:
    int bfs(vector<vector<int>> &adj, int n){
        queue<int> q;
        vector<int> dist(n,n+1);
        vector<int> vis(n,0);
        q.push(0);
        dist[0] = 0;
        vis[0] = 1;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            if(t==n-1) return dist[t];
            for(auto x:adj[t]){
                if(!vis[x]){
                    vis[x]=1;
                    q.push(x);
                    dist[x] = dist[t]+1;
                }
            }
        }
        return dist[n-1];
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i =0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        vector<int> res;
        for(auto x:queries){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            int ans = bfs(adj,n);
            res.push_back(ans);
        }
        return res;
    }
};