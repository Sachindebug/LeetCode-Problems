class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> zeroes;
        vector<int> ones;
        vector<vector<int>> res;
        unordered_map<int,int> ump;
        for(int i=0;i<matches.size();i++)
        {
            int x=matches[i][0];
            int y=matches[i][1];
            if(ump.find(x)==ump.end())
            {
                ump[x]=0;
            }
            ump[y]++;

        }
        for(auto x:ump)
        {
            if(x.second==0)
            {
                zeroes.push_back(x.first);
            }
            if(x.second==1)
            {
                ones.push_back(x.first);
            }
        }
        sort(zeroes.begin(),zeroes.end());
        sort(ones.begin(),ones.end());
        res.push_back(zeroes);
        res.push_back(ones);
        return res;


    }
};