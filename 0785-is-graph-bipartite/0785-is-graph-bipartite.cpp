class Solution {
public:
    void dfs(vector<vector<int>>& graph,int start,vector<int> &vis,vector<int> &color,int currColor)
    {
        vis[start] = 1;
        color[start] = currColor;
        for(auto x:graph[start])
        {
            if(!vis[x]) dfs(graph,x,vis,color,1-currColor);
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(graph,i,vis,color,0);
            }
        }
        //  check bi-partite here
        for(int i=0;i<n;i++) cout<<color[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            int curr = color[i];
            for(int x: graph[i])
            {
                if(color[x] == curr) return false;
            }
        }
        return true;
    }
};