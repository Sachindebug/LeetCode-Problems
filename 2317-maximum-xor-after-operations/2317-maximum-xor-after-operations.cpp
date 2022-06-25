class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int res=0;
        for(auto x:nums) res|=x;
        return res;
    }
};