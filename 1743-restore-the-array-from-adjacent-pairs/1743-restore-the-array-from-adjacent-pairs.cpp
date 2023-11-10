class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& pairs) {
        map<int,vector<int>> ump;
        for(auto x:pairs)
        {
            int a = x[0];
            int b = x[1];
            ump[a].push_back(b);
            ump[b].push_back(a);
        }
        int start=-1;
        for(auto x:ump)
        {
            if(ump[x.first].size()==1)
            {
                start=x.first;
                break;
            }
        }
        vector<int> ans;
        dfs(start, INT_MAX, ans,ump);
        return ans;
    }
    void dfs(int node, int prev, vector<int>& ans, map<int,vector<int>> &ump) {
        ans.push_back(node);
        for (int neighbor : ump[node]) {
            if (neighbor != prev) {
                dfs(neighbor, node, ans,ump);
            }
        }
    }
};