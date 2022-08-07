class Solution {
public:
    int longestIdealString(string s, int k) {
        int n=s.length();
        char c='/';
        vector<vector<int>> dp(n+1,vector<int>(26,-1));
        return recurse(s,0,c,k,dp);
    }
    int recurse(string &s,int idx,char c,int k,vector<vector<int>> &dp)
    {
        if(idx==s.length()) return 0;
        int res=0;
        if(c!='/' && dp[idx][c-'a']!=-1) return dp[idx][c-'a'];
        if(c=='/')
        {
            return max(recurse(s,idx+1,c,k,dp),1+recurse(s,idx+1,s[idx],k,dp));
        }
        if(abs(s[idx]-c)<=k)
        {
            res=max(res,1+recurse(s,idx+1,s[idx],k,dp));
        }
        res=max(res,recurse(s,idx+1,c,k,dp));
        dp[idx][c-'a']=res;
        return res;
    }
};