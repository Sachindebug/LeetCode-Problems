// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int count(unordered_map<int,vector<int>> &ump,vector<bool> &vis,int s,int d)
    {
        if(s==d) return 1;
        if(ump[s].size()==0) return 0;
        int res=0;
        vis[s]=true;
        for(int i=0;i<ump[s].size();i++)
        {
          
            
                res+=count(ump,vis,ump[s][i],d);
            
        }
        return res;
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    unordered_map<int,vector<int>> ump;
	    for(auto x:edges)
	    {
	        ump[x[0]].push_back(x[1]);
	    }
	    vector<bool> vis(n,false);
	    return count(ump,vis,s,d);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends