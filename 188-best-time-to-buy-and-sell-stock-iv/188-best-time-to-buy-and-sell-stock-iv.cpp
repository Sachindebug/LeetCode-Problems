class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int c=0;
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return recurse(prices,c,0,0,dp,k);
    }
    int recurse(vector<int> &arr,int c,int idx,int b,vector<vector<vector<int>>> &dp,int k)
    {
        if(idx>=arr.size()) return 0;
        if(dp[idx][b][c]!=-1) return dp[idx][b][c];
        if(!b)
        {
            if(c<k)
            {
                return dp[idx][b][c]=max(-arr[idx]+recurse(arr,c+1,idx+1,!b,dp,k),
                                         recurse(arr,c,idx+1,b,dp,k));
            }
        }
        else return dp[idx][b][c]=max(arr[idx]
                                      +recurse(arr,c,idx+1,!b,dp,k)
                                      ,recurse(arr,c,idx+1,b,dp,k));
        return 0;
    }
};