class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> ump;
        for(auto x:nums) ump[x]++;
        for(auto x:ump) if(x.second>1) return x.first;
        return -1;
    }
};