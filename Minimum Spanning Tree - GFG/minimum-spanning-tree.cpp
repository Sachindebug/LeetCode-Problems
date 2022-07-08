// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,0});
        int par[V],key[V];
        bool mst[V];
        for(int i=0;i<V;i++)
        {
            par[i]=-1;
            key[i]=INT_MAX;
            mst[i]=false;
        }
        key[0]=0;
        while(!pq.empty())
        {
            int u=pq.top().second;
            pq.pop();
            mst[u]=true;
            for(auto it:adj[u])
            {
                int v=it[0];
                int wt=it[1];
                if(mst[v]==false && wt<key[v])
                {
                    par[v]=u;
                    key[v]=wt;
                    pq.push({wt,v});
                    
                }
            }
        }
        long long int res=0;
        for(int i=1;i<V;i++) res+=key[i];
        return res;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends