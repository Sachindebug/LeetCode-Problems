class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int end=n-1;
        int l=0,r=0;
        unordered_map<char,int> ump;
        int count=0;
        while(r<n)
        {
            ump[s[r]]++;
            while(ump['a'] && ump['b'] && ump['c'])
            {
                count+=(1+end-r);
                ump[s[l]]--;
                l++;
            }
            r++;
        }
        return count;
    }
};