class Solution {
public:
    map<int,vector<int>> moves;
    int mod = 1000000007;
    int knightDialer(int n) {
        moves.insert({1,{6,8}});
        moves.insert({2,{7,9}});
        moves.insert({3,{4,8}});
        moves.insert({4,{0,3,9}});
        moves.insert({5,{}});
        moves.insert({6,{0,1,7}});
        moves.insert({7,{2,6}});
        moves.insert({8,{1,3}});
        moves.insert({9,{2,4}});
        moves.insert({0,{4,6}});
        int ans = 0;
        vector<vector<int>> dp(10,vector<int>(n+1,-1));
        for(int i=0;i<10;i++)
        {
            ans+=recurse(i,n,dp);
            ans=ans%mod;
        }
        return ans;
    }
    int recurse(int pos, int n, vector<vector<int>> &dp)
    {
        if(n==1) return 1;
        if(dp[pos][n]!=-1) return dp[pos][n]; 
        int ans = 0;
        for(auto x:moves[pos])
        {
            ans+=recurse(x,n-1,dp);
            ans = ans%mod;
        }
        return dp[pos][n]=ans;
    }
};