class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long int res=0;
        long long int val=1;
        long long int ans=0;
        int idx=-1;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(val>k)
            {
                idx=i;
                break;
            }
            if(s[i]=='0')
            {
                res++;
            }
            else
            {
                if(ans+val<=k)
                {
                    res++;
                    ans+=val;
                }
                else
                {
                    idx=i;
                    break;
                }
            }
            val*=2;
        }
        for(int i=idx;i>=0;i--)
        {
            if(s[i]=='0')
            {
                res++;
            }
        }
        return res;
    }
};