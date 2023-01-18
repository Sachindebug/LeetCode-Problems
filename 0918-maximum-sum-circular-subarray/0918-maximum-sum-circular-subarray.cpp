class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        for(auto x:nums) sum+=x;
        if(minSubArray(nums)==sum) return maxSubArray(nums);
        return max({maxSubArray(nums),sum-minSubArray(nums)});
    }
    int maxSubArray(vector<int>& nums) {
        bool allneg=true;
        for(auto x:nums) if(x>=0) allneg=false;
        if(allneg) return *max_element(nums.begin(),nums.end());
        int currmax=0;
        int maxtill=INT_MIN;
        for(auto x:nums)
        {
            currmax=max(x,currmax+x);
            maxtill=max(maxtill,currmax);
        }
        return maxtill;
    }
    int minSubArray(vector<int>& nums) {
        int currmin=0;
        int mintill=INT_MAX;
        for(auto x:nums)
        {
            currmin=min(x,currmin+x);
            mintill=min(mintill,currmin);
        }
        return mintill;
    }
};