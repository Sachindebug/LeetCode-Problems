class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& nums, int m, int n) {
        int s = nums.size();
        if(s!=m*n) return {};
        int idx = 0;
        vector<vector<int>> res(m,vector<int> (n));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                res[i][j] = nums[idx];
                idx++;
            }
        }
        return res;
    }
};