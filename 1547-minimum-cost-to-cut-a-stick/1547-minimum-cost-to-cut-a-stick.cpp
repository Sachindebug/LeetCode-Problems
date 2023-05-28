class Solution {
public:
    int minCost(int n, vector<int>& arr) {
        int i=1;
        int j=arr.size();
        int m=j;
        arr.push_back(n);
        arr.insert(arr.begin(),0);
        sort(arr.begin(),arr.end());
        vector<vector<int>> dp(m+2,vector<int>(m+2,0));
        for(int i=m;i>0;i--)
        {
            for(int j=1;j<=m;j++)
            {
                if(i>j) continue;
                int mini=INT_MAX;
                for(int k=i;k<=j;k++)
                {
                    int cost = arr[j+1]-arr[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;
                
            }
        }
        return dp[1][m];
    }
    
};