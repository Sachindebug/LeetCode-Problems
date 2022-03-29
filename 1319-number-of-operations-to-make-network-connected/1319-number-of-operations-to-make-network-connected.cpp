class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& c) {
        int count=0;
        unordered_map<int,vector<int>> ump;
        for(int i=0;i<c.size();i++)
        {
            ump[c[i][0]].push_back(c[i][1]);
            ump[c[i][1]].push_back(c[i][0]);
            count++;

        }
        if(count<n-1)
        {
            return -1;
        }
        count=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(ump,i,vis);
                count++;
            }
        }
        return count-1;
        
    }
    void dfs(unordered_map<int,vector<int>> &ump,int s,vector<bool> &vis)
    {
        vis[s]=true;
        for(int i=0;i<ump[s].size();i++)
        {
            if(!vis[ump[s][i]])
            {
                dfs(ump,ump[s][i],vis);
            }
        }
    }
};