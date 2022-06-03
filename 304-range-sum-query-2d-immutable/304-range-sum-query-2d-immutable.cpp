class NumMatrix {
    vector<vector<int>> arr;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        arr=matrix;
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j==0)
                {
                    continue;
                }
                else
                {
                    arr[i][j]+=arr[i][j-1];
                }
                
            }
            
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        
        for(int i=row1;i<=row2;i++)
        {
            if(col1!=0)
                sum+=(arr[i][col2]-arr[i][col1-1]);
            else
                sum+=(arr[i][col2]);
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */