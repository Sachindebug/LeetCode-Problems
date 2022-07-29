class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> ump;
        for(auto x:s) ump[x]++;
        set<char> st;
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            st.insert(s[i]);
            ump[s[i]]=ump[s[i]]-1;
            if(ump[s[i]]==0) ump.erase(s[i]);
            if(st.size()==ump.size()) count++;
        }
        return count;
    }
};