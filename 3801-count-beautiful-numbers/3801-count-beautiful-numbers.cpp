class Solution {
public:
    unordered_map<string, int>dp;
    int tdp(int in, int tight, int sum, int pro, string&s){
        if(in>=s.length()){
            return ((sum>0) && (pro%sum == 0));
        }
        string state = to_string(in) + "+" + to_string(tight) + "+" + to_string(sum) + "+" + to_string(pro);
        if(dp.count(state))return dp[state];
        int lim = (tight==1)?s[in]-'0':9;
        int ans=0;
        for(int i=0;i<=lim;i++){
            int newpro = pro*i;
            if(i+sum == 0) newpro=1;
            ans+=tdp(in+1, tight & (lim==i), sum+i, newpro, s);
        }
        return dp[state]=ans;
    }
    int beautifulNumbers(int l, int r) {
        string left = to_string(l-1);
        string right = to_string(r);
        int rightans = tdp(0, 1, 0, 1, right);
        dp.clear();
        int leftans = tdp(0, 1, 0, 1, left);
        return rightans-leftans;
    }
};