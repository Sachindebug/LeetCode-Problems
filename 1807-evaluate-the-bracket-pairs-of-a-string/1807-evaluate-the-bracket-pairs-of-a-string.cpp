class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string> ump;
        for(auto x:knowledge)
        {
            auto p=x[0],q=x[1];
            ump[p]=q;
        }
        string res="";
        string t="";
        bool found=false;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                found=true;
            }
            else if(s[i]==')')
            {
                found=false;
                if(ump.find(t)==ump.end())
                {
                    res+='?';
                }
                else
                {
                    res+=ump[t];
                }
                t="";
            }
            else
            {
                if(found) t+=s[i];
                else res+=s[i];
            }
        }
        return res;
    }
};