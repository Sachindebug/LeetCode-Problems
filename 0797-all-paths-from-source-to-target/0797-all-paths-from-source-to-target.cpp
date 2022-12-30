class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        return recurse(graph,0);
    }
    vector<vector<int>> recurse(vector<vector<int>>& graph,int s)
    {
        vector<vector<int>> res;
        int n=graph.size();
        if(s==n-1)
        {
            return {{s}};
        }
        for(int i=0;i<graph[s].size();i++)
        {
            vector<vector<int>> prev=recurse(graph,graph[s][i]);
            for(int j=0;j<prev.size();j++)
            {
                prev[j].insert(prev[j].begin(),s);
                res.push_back(prev[j]);
            }
            
        }
        return res;
    }
};