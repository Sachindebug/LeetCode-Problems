class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,-1);
        return recurse(questions,0,dp);
    }
    long long recurse(vector<vector<int>>& nums, int idx,vector<long long> &dp){
        if(nums.size()<=idx) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=max(nums[idx][0]+recurse(nums,1+idx+nums[idx][1],dp),recurse(nums,idx+1,dp));
    }
};