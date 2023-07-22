class Solution {
public:
    long long recurse(vector<int> &nums, int idx, int parity, int x, vector<vector<long long >> &dp)
    {
        if(idx==nums.size()) return 0;
        if(dp[idx][parity]!=-1) return dp[idx][parity];
        long long res=recurse(nums,idx+1,parity,x,dp);
        if(nums[idx]%2==parity)
        {
            res=max(res,nums[idx]+recurse(nums,idx+1,nums[idx]%2,x,dp));
        }
        else
        {
            res=max(res,nums[idx]-x+recurse(nums,idx+1,nums[idx]%2,x,dp));
        }
        return dp[idx][parity]=res;
        
    }
    long long maxScore(vector<int>& nums, int x) {
        vector<vector<long long>> dp(nums.size()+1,vector<long long>(2,-1));
        return nums[0]+recurse(nums,1,nums[0]%2,x,dp);
    }
};