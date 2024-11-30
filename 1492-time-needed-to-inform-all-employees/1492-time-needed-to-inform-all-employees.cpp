class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        vector<int> vis(n,0);
        vector<int> dis(n,0);
        queue<int> q;
        q.push(headID);
        dis[headID]=informTime[headID];
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            for(auto x:adj[p]){
                dis[x]=dis[p]+informTime[x];
                q.push(x);
            }
        }
        int res=INT_MIN;
        for(int i=0;i<n;i++)
        {
            res=max(res,dis[i]);
        }
        return res;
    }
};