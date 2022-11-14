class Solution {
public:
    int mod=1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp1(high+2,-1);
        vector<int> dp2(high+2,-1);

        int a=recurse(0,zero,one,low-1,dp1);
        int b=recurse(0,zero,one,high,dp2);
        return (b-a+mod)%mod;
    }
    int recurse(int sum,int a,int b,int l,vector<int> &dp)
    {
        if(sum>l) return 0;
        if(dp[sum]!=-1) return dp[sum];
        int res=0;
        if(sum+a<=l) res+=(1+recurse(sum+a,a,b,l,dp));
        res%=mod;
        if(sum+b<=l) res+=(1+recurse(sum+b,a,b,l,dp));
        res%=mod;
        return dp[sum]=res;

    }
    
};