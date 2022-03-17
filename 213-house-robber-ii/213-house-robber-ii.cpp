class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n+2,-1);
        vector<int> dp2(n+2,-1);
        return max(recurse(nums,0,n-1,dp1),recurse(nums,1,n,dp2));
    }
    int recurse(vector<int> arr,int idx,int n,vector<int> &dp)
    {
        if(idx>=n)
        {
            dp[idx]=0;
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
       
        
        dp[idx]=max(arr[idx]+recurse(arr,idx+2,n,dp),recurse(arr,idx+1,n,dp));
        return dp[idx];
    }
};