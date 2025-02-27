class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        if (n < 3) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(n, 2));
        // optimize
        unordered_map<int, int> idx_map;
        for(int i = 0; i < n; i++)
            idx_map[A[i]] = i;
        
        int ans = 1;
        
        for(int j = 0; j < n; j++){
             for(int i = 0; i < j; i++){
                 int target = A[j] - A[i];
                 if(idx_map.count(target) > 0){
                     int k = idx_map[target];
                     if(k < i){
                         dp[i][j] = max(dp[i][j], dp[k][i] + 1);
                         ans = max(ans, dp[i][j]);
                     }
                 }
            }
        }
        return ans < 3 ? 0 : ans;
    }
    
};