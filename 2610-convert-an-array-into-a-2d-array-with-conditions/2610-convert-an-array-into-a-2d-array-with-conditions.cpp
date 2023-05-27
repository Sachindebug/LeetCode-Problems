class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,vector<int>> ump;
        map<int,int> cmp;
        vector<vector<int>> res;
        for(auto x:nums)
        {
            cmp[x]++;
            ump[cmp[x]].push_back(x);
            
        }
        for(auto x:ump)
        {
            res.push_back(x.second);
        }
        return res;
    }
};