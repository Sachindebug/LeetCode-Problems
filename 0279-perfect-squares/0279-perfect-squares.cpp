class Solution {
public:
    int numSquares(int n) {
        int dp[10001];
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<=n;i++)
        {
            int x=sqrt(i);
            if(x*x==i)
            {
                dp[i]=1;
            }
            else
            {
                int res=INT_MAX;
                for(int j=1;j<i;j++)
                {
                    
                    if(dp[j]==1)
                    {
                        res=min(res,1+dp[i-(j)]);
                    }
                }
                dp[i]=res;
            }
        }
        return dp[n];
        
    }
    
};