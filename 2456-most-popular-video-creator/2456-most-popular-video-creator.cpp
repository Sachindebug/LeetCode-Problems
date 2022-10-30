class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& id, vector<int>& views) {
        vector<vector<string>> ans;
        unordered_map<string,set<pair<int,string>>> maxid;
        unordered_map<string,long long> sum;
        int n=c.size();
        for(int i=0;i<n;i++)
        {
            sum[c[i]]+=views[i];
            maxid[c[i]].insert({-views[i],id[i]});
        }
        long long res=0;
        for(auto x:sum)
        {
            if(x.second>res)
            {
                res=x.second;
            }
        }
        for(auto x:sum)
        {
            if(x.second==res)
            {
                auto it = *(maxid[x.first].begin());
                auto y=it.second;
                
                ans.push_back({x.first,y});
            }
        }
        return ans;
    }
};