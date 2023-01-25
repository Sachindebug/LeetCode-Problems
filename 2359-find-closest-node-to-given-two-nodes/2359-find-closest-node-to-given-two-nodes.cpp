class Solution {
    
public:
    void dfs(vector<vector<int>> &adj,vector<int> &dis,vector<bool> &vis,int node)
    {
        vis[node]=true;
        for(auto x:adj[node])
        {
            if(!vis[x])
            {
                dis[x]=dis[node]+1;
                dfs(adj,dis,vis,x);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n=edges.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1)
            adj[i].push_back(edges[i]);
        }
        vector<int> dis1(n,INT_MAX);
        vector<int> dis2(n,INT_MAX);
        vector<bool> vis1(n,false);
        vector<bool> vis2(n,false);
        dis1[node1]=0;
        dis2[node2]=0;
        dfs(adj,dis1,vis1,node1);
        dfs(adj,dis2,vis2,node2);
        int res=INT_MAX;
        int idx=-1;
        for(int i=0;i<n;i++)
        {
            if(dis1[i]!=INT_MAX && dis2[i]!=INT_MAX)
            {
                if(max(dis1[i],dis2[i])<res)
                {
                    res=max(dis1[i],dis2[i]);
                    idx=i;
                }
               
            }
            
            
        }
        return idx;
   }
};