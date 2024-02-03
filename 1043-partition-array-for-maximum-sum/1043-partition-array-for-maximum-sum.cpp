class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1,-1);
        return recurse(arr,k,0,dp);
    }
    int recurse(vector<int>& arr, int k, int idx,vector<int> &dp)
    {
        if(idx>=arr.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int mx = 0;
        int res = 0;
        for(int i = idx;i<arr.size() && i<idx+k ;i++)
        {
            mx = max(mx,arr[i]);
            res = max(res,(mx*(i-idx+1))+recurse(arr,k,i+1,dp));
        }
        return dp[idx]=res;
    }
};