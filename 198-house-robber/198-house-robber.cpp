class Solution {
public:
    
    
    int rob(vector<int>& nums) 
    {
        int dp[nums.size()+1];
        for(int i=0;i<nums.size();i++)
        {
            dp[i]=-1;
        }
        
        return recurse(nums,nums.size()-1,dp);
        
    }
    int recurse(vector<int> arr,int n,int dp[])
    {
        
        if(n<0)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        if(n==0)
        {
            dp[n]=arr[n];
            return arr[n];
        }
        
        dp[n]=max(arr[n]+recurse(arr,n-2,dp),recurse(arr,n-1,dp));
        return max(arr[n]+recurse(arr,n-2,dp),recurse(arr,n-1,dp));
        
    }
};