class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        set<string> st(d.begin(),d.end());
        string res = "";
        string temp = "";
        int i = 0;
        while(i<s.length())
        {
            if(s[i]==' ')
            {
                res+=temp;
                res+=" ";
                temp="";
            }
            else
            {
                temp+=s[i];
            }
            if(st.find(temp)!=st.end())
            {
                res+=temp;
                res+=" ";
                temp="";
                while(i<s.length() && s[i]!=' ')
                {
                    i++;
                }
            }
            i++;
        }
        if(temp=="") res.pop_back();
        else res+=temp;
        return res;
    }
};