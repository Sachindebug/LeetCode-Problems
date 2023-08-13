class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return recurse(0,nums,dp);
    }
    int recurse(int idx, vector<int> &nums, vector<int> &dp)
    {
        if(idx==nums.size()) return 1;
        if(idx+1==nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int res=0;
        if(idx+1< nums.size() and nums[idx]==nums[idx+1])
        {
            res = res | recurse(idx+2,nums,dp);
        }
        if(idx+2<nums.size() and nums[idx]+1 == nums[idx+1] and nums[idx+1]+1==nums[idx+2])
        {
            res = res| recurse(idx+3,nums,dp);
            
        }
        if(idx+2<nums.size() and nums[idx] == nums[idx+1] and nums[idx+1]==nums[idx+2])
        {
            res = res| recurse(idx+3,nums,dp);
            
        }
        
        return dp[idx]=res;
    }
};