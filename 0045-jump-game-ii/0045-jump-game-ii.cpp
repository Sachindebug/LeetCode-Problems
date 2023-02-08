class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return recurse(n-1,nums,dp);
        
    }
    int recurse(int ridx,vector<int> &nums,vector<int> &dp)
    {
        if(dp[ridx]!=-1) return dp[ridx];
        if(ridx==0) 
        {
            dp[ridx]=0;
            return 0;
        }
        int res=INT_MAX;
        for(int i=0;i<ridx;i++)
        {
            if(ridx-i<=nums[i])
            {
               res=min(res,1+recurse(i,nums,dp)); 
            }
        }
        dp[ridx]=res;
        return dp[ridx];
    }
};