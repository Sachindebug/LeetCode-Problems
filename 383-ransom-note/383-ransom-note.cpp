class Solution {
public:
    bool canConstruct(string s, string t) {
        unordered_map<char,int> ump;
        for(int i=0;t[i];i++)
        {
            ump[t[i]]++;
        }
        for(int i=0;s[i];i++)
        {
            if(ump.find(s[i])==ump.end() || ump[s[i]]<=0)
            {
                return false;
            }
            ump[s[i]]--;
        }
        return true;
        
    }
};