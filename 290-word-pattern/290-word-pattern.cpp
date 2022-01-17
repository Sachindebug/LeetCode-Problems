class Solution {
public:
    bool wordPattern(string t, string s) {
       vector<string> temp;
        string res="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                temp.push_back(res);
                res="";
                
            }
            else
            {
                res+=s[i];
            }
        }
        temp.push_back(res);
        if(temp.size()!=t.length()) return false;
        unordered_map<char,string> ump;
        unordered_map<string,char> ump1;

        for(int i=0;i<t.length();i++)
        {
            if(ump.find(t[i])==ump.end() && ump1.find(temp[i])==ump1.end())
            {
                ump[t[i]]=temp[i];
                ump1[temp[i]]=t[i];
                
            }
            else
            {
                if(ump[t[i]]!=temp[i] || ump1[temp[i]]!=t[i]) return false;
            }
        }
        return true;
        
    }
};