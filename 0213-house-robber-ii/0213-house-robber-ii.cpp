class Solution {
public:
    int n;
    int helper(int i, int start, vector<vector<int>>& dp, vector<int>& nums){
        if(i<0 || (i==0 && start==0)) return 0;
        if(dp[i][start]!=-1) return dp[i][start];
        int pick= nums[i]+helper(i-2,start,dp,nums);
        int nonpick= helper(i-1,start,dp,nums);
        return dp[i][start]=max(pick,nonpick);
    }
    
    int rob(vector<int>& nums) {
        n=nums.size();
        if(n==1) return nums[0];
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return max(helper(n-1,0,dp,nums), helper(n-2,1,dp,nums));
    }
};