class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> ump;
        for(auto x:nums)
        {
            ump[x]++;
        }
        vector<pair<int,int>> temp;
        for(auto x:ump)
        {
            temp.push_back({x.first,x.second});
        }
        sort(temp.begin(),temp.end(),myfun);
        vector<int> res;
        for(int i=0;i<temp.size();i++)
        {
            if(res.size()<k)
            res.push_back(temp[i].first);
        }
        return res;
        

    }
    static bool myfun(pair<int,int> p1,pair<int,int> p2)
    {
        if(p1.second>p2.second) return true;
        return false;
    }
};