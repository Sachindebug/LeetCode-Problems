class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<int,int> indegree;
        map<int,set<int>> paths;
        for(auto x:roads) 
        {
            int a = x[0];
            int b = x[1];
            indegree[a]++;
            indegree[b]++;
            paths[a].insert(b);
            paths[b].insert(a);
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int ans = indegree[i];
                ans += indegree[j];
                if(paths[i].find(j)!=paths[i].end())
                {
                    ans-=1;
                }
                res=max(res,ans);

            }
        }
        return res;
    }
};