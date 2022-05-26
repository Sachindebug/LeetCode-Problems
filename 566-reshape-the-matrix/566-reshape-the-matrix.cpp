class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size();
        int n=mat[0].size();
        if((n*m)!=(r*c))
        {
            return mat;
        }
        vector<vector<int>> res(r,vector<int>(c,0));
        //main operations
       for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int k = i * n + j;
                res[k / c][k % c] = mat[i][j];
            }
        }
        return res;
        
    }
};