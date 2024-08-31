class Solution {
public:
    int manhattDist(vector<int>&v1 , vector<int>&v2)
    {
        return abs(abs(v1[0]-v2[0]) + abs(v1[1]-v2[1]));
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,int>> adj[n];
        for(int i=0; i<n ; i++)
        {
            for(int j=i+1;j<n ; j++)
            {
                adj[i].push_back({j , manhattDist(points[i] , points[j])});
                adj[j].push_back({i , manhattDist(points[i] , points[j])});
            }
        }

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        vector<int> vis(n,0);
        pq.push({0,0});
        int Cost=0;
        while(!pq.empty())
        {
            auto it = pq.top(); 
            pq.pop();
            int CurrNode = it.second ;
            int topEdgwWt = it.first;
            
            if(vis[CurrNode]==1) continue;
            
            vis[CurrNode]=1;
            
            Cost+=topEdgwWt;
            for(auto it: adj[CurrNode])
            {
                int adjPoint=it.first;
                int edWt=it.second;
                if(!vis[adjPoint])
                {
                    pq.push({edWt , adjPoint});
                }
            }
        }
        return Cost;
    }
};