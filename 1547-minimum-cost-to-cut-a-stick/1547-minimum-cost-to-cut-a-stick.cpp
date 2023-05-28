class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int i=1;
        int j=cuts.size();
        int m=cuts.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return recurse(cuts,1,j,dp);
    }
    int recurse(vector<int> &arr,int i,int j,vector<vector<int>> &dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<=j;k++)
        {
            int cost = arr[j+1]-arr[i-1]+recurse(arr,i,k-1,dp)+recurse(arr,k+1,j,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
};