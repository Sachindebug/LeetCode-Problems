class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<=k) return false;
        set<string> st;
        string temp="";
        for(int i=0;i<k;i++)
        {
            temp+=s[i];
        }
        st.insert(temp);
        for(int i=k;i<s.length();i++)
        {
            temp.erase(temp.begin());
            temp+=s[i];
            st.insert(temp);
        }
        return st.size()==pow(2,k);
        
    }
};