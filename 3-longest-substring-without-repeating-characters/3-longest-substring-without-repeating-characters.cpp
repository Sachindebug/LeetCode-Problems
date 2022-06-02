class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        int l=0,r=0;
        int n=s.length();
        set<int> st;
        while(r<n)
        {
            if(st.find(s[r])==st.end())
            {
                len=max(r-l+1,len);
                st.insert(s[r]);
                r++;
            }
            else
            {
                st.erase(s[l]);
                l++;
            }
        }
        return len;
        
    }
};