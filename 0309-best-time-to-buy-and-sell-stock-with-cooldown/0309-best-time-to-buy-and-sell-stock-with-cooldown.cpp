class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return recurse(prices,0,-1,dp);
    }
    int recurse(vector<int>& prices, int currIdx, int prevIdx,vector<vector<int>> &dp){
        if(currIdx>=prices.size()) return 0;
        if(dp[currIdx][prevIdx+1]!=-1) return dp[currIdx][prevIdx+1];
        int res = recurse(prices,currIdx+1,prevIdx,dp);
        if(prevIdx==-1){
            res = max(res,recurse(prices,currIdx+1,currIdx,dp));
        }
        else if(prices[currIdx]>prices[prevIdx]) {
            res = max(res,prices[currIdx]-prices[prevIdx]+recurse(prices,currIdx+2,-1,dp));
        }
        return dp[currIdx][prevIdx+1] = res;
    }
};