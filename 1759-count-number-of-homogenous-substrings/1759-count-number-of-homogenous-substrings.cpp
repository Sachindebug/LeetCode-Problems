class Solution {
public:
    int countHomogenous(string s) {
        long long int count = 1;
        long long int res = 0;
        long long int mod = 1000000007;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==s[i-1])
            {
                count++;
            }
            else
            {
                res += ((count%mod)*((count+1)%mod))/2;
                res = res%mod;
                count=1;
            }
        }
        res += ((count%mod)*((count+1)%mod))/2;
        res = res%mod;
        return res;
        
    }
};