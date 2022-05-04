class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // vector<vector<int>> dp(n,vector<int> (n,0));
        // dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0)
                {
                    triangle[i][j]=triangle[i-1][j]+triangle[i][j];
                }
                else if(j==i)
                {
                     triangle[i][j]=triangle[i-1][j-1]+triangle[i][j]; 
                }
                else
                {
                    triangle[i][j]=min(triangle[i-1][j]+triangle[i][j],triangle[i-1][j-1]+triangle[i][j]);
                }
            }
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++)
        {
           
            res=min(res,triangle[n-1][i]);
        }
        return res;
        
    }
    
};