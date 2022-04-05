class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> time;
        for(int i=0;i<times.size();i++)
        {
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            time[u].push_back({w,v});
        }
        vector<int> dis(n+1,INT_MAX);
        set<pair<int,int>> s;
        dis[k]=0;
        s.insert({0,k});
        while(!s.empty())
        {
            auto it=s.begin();
            int node=it->second;
            int nodeDist=it->first;
            s.erase(it);
            for(auto x:time[node])
            {
                int nbr=x.second;
                int currEdge=x.first;
                if(nodeDist+currEdge<dis[nbr])
                {
                    // auto f=s.find({dis[nbr],nbr});
                    // if(f!=s.end())
                    // {
                    //     s.erase(f);
                    // }
                    dis[nbr]=nodeDist+currEdge;
                    s.insert(make_pair(dis[nbr],nbr));
                }
            }
        }
        int res=INT_MIN;
        for(int i=1;i<n+1;i++)
        {
            res=max(dis[i],res);
        }
        return res==INT_MAX?-1:res;
    }
};