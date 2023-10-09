class Solution {
public:
    bool stoneGame(vector<int>& nums) {
        int sum = 0;
        for(auto x:nums) sum+=x;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int res = recurse(nums,0,nums.size()-1,dp);
        // cout<<res<<endl;
        return res>sum-res;
    }
    int recurse(vector<int> &nums, int i, int j,vector<vector<int>> &dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res = nums[i]+recurse(nums,i+1,j-1,dp);
        res = max(res,nums[i]+recurse(nums,i+2,j,dp));
        res = max(res,nums[j]+recurse(nums,i+1,j-1,dp));
        res = max(res,nums[i]+recurse(nums,i,j-2,dp));
        return dp[i][j]=res;
    }
};