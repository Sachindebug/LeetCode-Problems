class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);
        dfs(rooms,0,vis);
        for(int i=0;i<n;i++)
        {
            if(!vis[i]) return false;
        }
        return true;
    }
    void dfs(vector<vector<int>>& rooms,int s,vector<bool> &vis)
    {
        vis[s]=true;
        for(int i=0;i<rooms[s].size();i++)
        {
            if(!vis[rooms[s][i]])
            {
                dfs(rooms,rooms[s][i],vis);
            }
        }
    }
};