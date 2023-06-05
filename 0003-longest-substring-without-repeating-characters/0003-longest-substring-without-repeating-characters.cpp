class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> ump;
        int res=0;
        int i=0;
        int j=0;
        while(j<s.length())
        {
            if(ump.find(s[j])==ump.end())
            {
                res=max(res,j-i+1);
            }
            else
            {
                while(ump[s[j]]>0)
                {
                    ump[s[i]]=ump[s[i]]-1;
                    i++;
                }
                res=max(res,j-i+1);
            }
            ump[s[j]]++;
            j++;
        }
        
        return res;
    }
};