class Graph {
public:
    unordered_map<int,vector<pair<int,int>>> ump;
    int size;
    Graph(int n, vector<vector<int>>& edges) {
        for(auto x:edges){
            int a = x[0];
            int b = x[1];
            int w = x[2];
            ump[a].push_back({b,w});
        }
        size=n;
    }
    
    void addEdge(vector<int> x) {
        int a = x[0];
        int b = x[1];
        int w = x[2];
        ump[a].push_back({b,w});
    }
    
    int shortestPath(int node1, int node2) {
        int s = node1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(size,INT_MAX);
        dist[s]=0;
        pq.push({0,s});
        while(!pq.empty())
        {
            auto x = pq.top();
            int d = x.first;
            int ele = x.second;
            pq.pop();
            for(auto it:ump[ele])
            {
                int w = it.second;
                int node = it.first;
                if(d+w<dist[node])
                {
                    dist[node] = d+w;
                    pq.push({dist[node],node});
                }
            }
        }
        return dist[node2]<INT_MAX?dist[node2]:-1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */