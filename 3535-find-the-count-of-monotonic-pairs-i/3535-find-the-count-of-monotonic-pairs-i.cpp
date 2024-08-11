class Solution {
private:
    int MOD = 1000000007;
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(52,vector<int>(52,-1)));
        return recurse(nums,0,-1,51,dp);
    }
    int recurse(vector<int>& nums, int idx, int mn, int mx,vector<vector<vector<int>>> &dp){
        if(idx==nums.size()) return 1;
        if(dp[idx][mn+1][mx]!=-1) return dp[idx][mn+1][mx];
        int res = 0;
        for(int i = max(mn,0);i<=nums[idx];i++){
            for(int j = min(nums[idx],mx);j>=0;j--){
                if(i+j==nums[idx]) {
                    res += recurse(nums,idx+1,i,j,dp);
                    res = res%MOD;
                }
            }
        }
        return dp[idx][mn+1][mx]=res;
    }
};