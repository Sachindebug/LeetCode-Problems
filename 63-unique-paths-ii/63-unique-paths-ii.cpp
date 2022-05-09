class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        if(arr[0][0]==1) return 0;
        vector<vector<int>> res(n,vector<int>(m));
        res[0][0]=1;
        for(int i=1;i<n;i++)
        {
            res[i][0] = (arr[i][0] == 0 && res[i - 1][0] == 1) ? 1 : 0;
        }
        for(int i=1;i<m;i++)
        {
            res[0][i] = (arr[0][i] == 0 && res[0][i-1] == 1) ? 1 : 0;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(arr[i][j]==1) res[i][j]=0;
                else res[i][j]=res[i-1][j]+res[i][j-1];
                
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<res[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return res[n-1][m-1];
    }
};