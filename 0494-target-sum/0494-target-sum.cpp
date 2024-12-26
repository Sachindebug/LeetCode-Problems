class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(2001,-1));
        return recurse(nums,0,0,target,dp);
    }
    int recurse(vector<int>& nums, int idx,int curr, int target, vector<vector<int>> &dp){
        if(idx==nums.size()) 
            return curr==target;
        if(dp[idx][curr+1000]!=-1) return dp[idx][curr+1000];
        return dp[idx][curr+1000] = recurse(nums,idx+1,curr-nums[idx],target,dp)+recurse(nums,idx+1,curr+nums[idx],target,dp);
    }
};