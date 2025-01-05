class Solution {
public:
    int dp[10][2][10];
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        string num = to_string(n);
        return recurse(num,0,1,0);
    }
    int recurse(string &s, int idx, int bound, int cnt){
        if(idx==s.size()) return cnt;
        if(dp[idx][bound][cnt]!=-1) return dp[idx][bound][cnt];
        int limit = bound?s[idx]-'0': 9;
        int ans = 0;
        for(int i = 0;i<=limit;i++){
            int newCount = cnt+(i==1);
            ans+=recurse(s,idx+1,(bound & (i==(s[idx]-'0'))),newCount);
        }
        return dp[idx][bound][cnt] = ans;
    }
};