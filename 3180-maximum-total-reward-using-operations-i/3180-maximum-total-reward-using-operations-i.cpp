class Solution {
public:
    int dp[2001][4000];
    int maxTotalReward(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        memset(dp, -1, sizeof(dp));
        return recurse(nums,0,0);
    }
    int recurse(vector<int>& nums,int i, int sum)
    {
        if(i==nums.size()) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        if(nums[i]>sum)
        {
            return dp[i][sum]=max(recurse(nums,i+1,sum),nums[i]+recurse(nums,i+1,sum+nums[i]));
        }
        return dp[i][sum]=recurse(nums,i+1,sum);
    }
};