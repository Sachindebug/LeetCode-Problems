class Solution {
public:
   bool partition(int i,int sum, vector<int>& nums, vector<vector<int>>& dp){
        if(sum==0)
            return 1;
        if(i==0)
            return nums[0]==sum;
        if(dp[i][sum]!=-1)
            return dp[i][sum];

        int pick=false; 
        int notpick= partition(i-1,sum, nums, dp);
        if(nums[i]<=sum)
            pick=partition(i-1,sum-nums[i], nums, dp);
        return dp[i][sum]=pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totsum=0;
        for(int i=0; i<n;i++)
            totsum+= nums[i];

        if(totsum&1)
            return 0;

        int k=totsum/2;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return partition(n-1, k, nums, dp);
    }
};