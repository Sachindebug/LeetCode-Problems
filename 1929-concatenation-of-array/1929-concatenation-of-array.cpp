class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res(nums.begin(),nums.end());
        for(auto x:nums) res.push_back(x);
        return res;
        
    }
};