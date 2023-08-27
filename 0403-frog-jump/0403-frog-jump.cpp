class Solution {
public:
    unordered_map<int,int>ump;
    bool jump(int i, int k, int n, vector<int>& stones, vector<vector<int>>& dp){
        if(i==n-1)
            return 1;
        if(dp[i][k]!=-1)
            return dp[i][k];
        bool x=0,y=0,z=0;
        if(k>1 && ump.find(stones[i]+k-1) != ump.end())
            x=jump(ump[stones[i]+k-1],k-1,n,stones,dp);
        if(ump.find(stones[i]+k) != ump.end())
            y=jump(ump[stones[i]+k],k,n,stones,dp);
        if(ump.find(stones[i]+k+1) != ump.end())
            z=jump(ump[stones[i]+k+1],k+1,n,stones,dp);
        return dp[i][k]= (x || y || z);
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]!=1)
            return 0;
        int n=stones.size();
        if(n==2)
            return 1;
        for(int i=0; i<n; i++)
            ump[stones[i]]=i;
        vector<vector<int>>dp(2000,vector<int>(2001,-1));
        return jump(1,1,n,stones,dp);
    }
};