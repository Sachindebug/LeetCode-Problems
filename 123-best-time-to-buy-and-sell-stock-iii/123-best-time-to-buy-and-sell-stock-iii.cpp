class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int c=0;
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return recurse(prices,c,0,0,dp);
    }
    int recurse(vector<int> &arr,int c,int idx,int b,vector<vector<vector<int>>> &dp)
    {
        if(idx>=arr.size()) return 0;
        if(dp[idx][b][c]!=-1) return dp[idx][b][c];
        if(!b)
        {
            if(c<2)
            {
                return dp[idx][b][c]=max(-arr[idx]+recurse(arr,c+1,idx+1,!b,dp),recurse(arr,c,idx+1,b,dp));
            }
        }
        else return dp[idx][b][c]=max(arr[idx]+recurse(arr,c,idx+1,!b,dp),recurse(arr,c,idx+1,b,dp));
        return 0;
    }
};