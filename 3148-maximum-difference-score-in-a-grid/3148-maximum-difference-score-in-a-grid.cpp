class Solution {
public:
    int maxScore(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        dp[m-1][n-1]=a[m-1][n-1];
        int maxans=-100000000;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;
                else if(i==m-1){
                    int ans=dp[i][j+1]-a[i][j];
                    if(ans>maxans) maxans=ans;
                    dp[i][j]=max(a[i][j],dp[i][j+1]);
                }
                else if(j==n-1){
                    int ans=dp[i+1][j]-a[i][j];
                    if(ans>maxans) maxans=ans;
                    dp[i][j]=max(a[i][j],dp[i+1][j]);
                }
                else{
                    int ans=max(dp[i+1][j],dp[i][j+1])-a[i][j];
                    if(ans>maxans) maxans=ans;
                    dp[i][j]=max(a[i][j],max(dp[i+1][j],dp[i][j+1]));
                }
            }
        }
        return maxans;
    }
    int dp[1000][1000];
};