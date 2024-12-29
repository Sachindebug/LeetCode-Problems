class Solution {
public:
    int mod = 1e9 + 7;

    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int t = target.length();
        vector<vector<int>> wordCount(n, vector<int>(26, 0));
        for (const string& s : words) {
            for (int j = 0; j < n; j++) {
                wordCount[j][s[j] - 'a']++; 
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(t + 1, -1));
        return recurse(0, 0, target, wordCount,dp);
    }

    long long recurse(int i, int j, string &target, vector<vector<int>> &wordCount,vector<vector<int>> &dp) {
        if (j == target.length()) return 1;
        if (i == wordCount.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        char c = target[j];
        long long count = recurse(i + 1, j, target, wordCount,dp);
        count += 1ll*(wordCount[i][c - 'a'] * recurse(i + 1, j + 1, target, wordCount,dp)) % mod;
        count %= mod;
        return dp[i][j] = count;
    }
};