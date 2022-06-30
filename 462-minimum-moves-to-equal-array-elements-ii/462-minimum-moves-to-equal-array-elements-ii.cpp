class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int med;
        if(n%2) med=nums[n/2];
        else med=(nums[n/2]+nums[(n/2)-1])/2;
        int res=0;
        for(auto x:nums) res+=abs(med-x);
        return res;
    }
};