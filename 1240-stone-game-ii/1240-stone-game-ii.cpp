class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector dp(2, vector(n + 1, vector<int>(n + 1, -1)));
        return f(piles,0, 0, 1,dp);
    }
    int f(vector<int> &piles,int p,int i, int m,vector<vector<vector<int>>> &dp){
            if (i == piles.size()) {
                return 0;
            }
            if (dp[p][i][m] != -1) {
                return dp[p][i][m];
            }
            int n = piles.size();
            int res = p == 1 ? 1000000 : -1, s = 0;
            for (int x = 1; x <= min(2 * m, n-i); x++) {
                s += piles[i + x - 1];
                if (p == 0) {
                    res = max(res, s + f(piles,1, i + x, max(m, x),dp));
                }
                else {
                    res = min(res, f(piles,0, i + x, max(m, x),dp));
                }
            }
            return dp[p][i][m]=res;
        };
};