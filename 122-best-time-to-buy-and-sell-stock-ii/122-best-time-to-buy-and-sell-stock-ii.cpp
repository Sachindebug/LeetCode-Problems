class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        
        return recurse(prices,0,1,dp);
    }
    int recurse(vector<int> &arr,int idx,int b,vector<vector<int>> &dp)
    {
        if(idx>=arr.size()) return 0;
        if(dp[idx][b]!=-1) return dp[idx][b];
        
        if(b)
        {
            return dp[idx][b]=max(-arr[idx]+recurse(arr,idx+1,0,dp),recurse(arr,idx+1,1,dp));
        }
        else
        {
            return dp[idx][b]=max(arr[idx]+recurse(arr,idx+1,1,dp),recurse(arr,idx+1,0,dp));
        }
        
    }
};