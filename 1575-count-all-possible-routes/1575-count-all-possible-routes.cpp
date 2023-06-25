class Solution {
public:
    int mod=1000000007;
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        vector<vector<int>> dp(n+1,vector<int>(fuel+1,-1));
        return recurse(locations,start,finish,fuel,dp);
    }
    int recurse(vector<int> &arr, int s, int r, int f,vector<vector<int>> &dp)
    {
        
        if(f<0) return 0;
        if(dp[s][f]!=-1) return dp[s][f];
        int ans=0;
        if(s==r) ans=1;
        for(int i=0;i<arr.size();i++)
        {
            if(i!=s)
            {
                ans+=recurse(arr,i,r,f-abs(arr[i]-arr[s]),dp);
                ans=ans%mod;
            }
        }
        return dp[s][f]=ans%mod;
    }
};