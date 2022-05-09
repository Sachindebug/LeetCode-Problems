class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j==0)
                {
                    matrix[i][j]=matrix[i][j]+min(matrix[i-1][j],matrix[i-1][j+1]);
                }
                else if(j==m-1)
                {
                    matrix[i][j]=matrix[i][j]+min(matrix[i-1][j],matrix[i-1][j-1]);
                }
                else
                {
                    matrix[i][j]=matrix[i][j]+min({matrix[i-1][j-1],matrix[i-1][j+1],matrix[i-1][j]});
                }
            }
        }
        return *min_element(matrix[n-1].begin(),matrix[n-1].end());
    }
};