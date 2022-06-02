class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        int l=0,r=0;
        int n=s.length();
        map<int,int> ump;
        while(r<n)
        {
            if(ump.find(s[r])==ump.end())
            {
                len=max(r-l+1,len);
                ump[s[r]]=r;
                r++;
            }
            else
            {
                l=max(l,ump[s[r]]+1);
                ump[s[r]]=r;
                len=max(r-l+1,len);
                r++;

            }
        }
        return len;
        
    }
};