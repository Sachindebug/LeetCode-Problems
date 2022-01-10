class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> ump;
        for(auto num:nums)
        {
            ump[num]++;
        }
        int n=nums.size();
        n/=3;
        vector<int> res;
        for(auto x:ump)
        {
            if(x.second>n) res.push_back(x.first);
        }
        return res;
    }
};