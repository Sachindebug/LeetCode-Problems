class Solution {
public:
    int Memoization(vector<vector < int>> &dp, int ind, int amount, vector< int > &coins)
        {
            if (amount == 0)
                return 1;
            if (ind == coins.size())
                return 0;
            if (dp[ind][amount] != -1)
                return dp[ind][amount];
            if (coins[ind] > amount)
                return dp[ind][amount] = Memoization(dp, ind + 1, amount, coins);
            int pick = Memoization(dp, ind, amount - coins[ind], coins);
            int notPick = Memoization(dp, ind + 1, amount, coins);
            return dp[ind][amount] = pick + notPick;
        }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector < int>> dp(n + 1, vector<int> (amount + 1, -1));
        return Memoization(dp, 0, amount, coins);
    }
};