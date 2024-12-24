int dfs(int node,int par,vector<vector<int>> &adj,int &ans)
{
    int ret=1;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto it:adj[node])
    {
        if(it!=par)
        {
            int z=dfs(it,node,adj,ans);
            pq.push(z);
            if(pq.size()>2) pq.pop();
        }
    }
    if(pq.size()==2)
    {
        int z=pq.top();
        pq.pop();
        ret+=pq.top();
        ans=max(ans,z+pq.top());
    }
    else if(pq.size()==1)
    {
        ret+=pq.top();
        ans=max(ans,pq.top());
    }
    return ret;
}

int fdiameter(vector<vector<int>> &adj)
{
    int ans=0;
    int h=dfs(0,-1,adj,ans);
    return ans;
}

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2) {
        int n=e1.size();
        n++;
        int m=e2.size();
        m++;
        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);
        for(auto it:e1)
        {
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        for(auto it:e2)
        {
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        int d1=fdiameter(adj1);
        int d2=fdiameter(adj2);
        int ans=0;
        ans+=(d1+1)/2;
        ans+=(d2+1)/2;
        return max({d1,d2,ans+1});
    }
};