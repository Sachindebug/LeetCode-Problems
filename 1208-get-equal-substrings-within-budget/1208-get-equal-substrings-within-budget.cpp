class Solution {
public:
    int equalSubstring(string s, string t, int k) {
        int res = 0;
        int sum = 0;
        int i = 0,j = 0;
        while(j<s.size())
        {
            sum+=abs(s[j]-t[j]);
            while(sum>k)
            {
                sum-=abs(s[i]-t[i]);
                i++;
            }
            res = max(res,j-i+1);
            j++;
        }
        return res;
    }
};