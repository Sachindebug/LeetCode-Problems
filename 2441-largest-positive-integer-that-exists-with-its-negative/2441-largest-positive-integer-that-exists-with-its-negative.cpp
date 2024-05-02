class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> s;
        for(auto x:nums) s.insert(x);
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<nums.size();i++){
            if(s.find(-nums[i])!=s.end()) return nums[i];
        }
        return -1;
    }
};