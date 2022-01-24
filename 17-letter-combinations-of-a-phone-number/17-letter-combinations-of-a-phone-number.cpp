class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> ump;
        if(digits.length()==0) return {};
        ump['2']="abc";
        ump['3']="def";
        ump['4']="ghi";
        ump['5']="jkl";
        ump['6']="mno";
        ump['7']="pqrs";
        ump['8']="tuv";
        ump['9']="wxyz";
        vector<string> res=recurse(digits,ump);
        return res;
    }
    vector<string> recurse(string s,unordered_map<char,string> ump)
    {
        if(s.length()==1)
        {
            vector<string> res;
            string a="";
            for(int i=0;i<ump[s[0]].length();i++)
            {
                a="";
                a+=ump[s[0]][i];
                res.push_back(a);
                
            }
            return res;
        }
        vector<string> res1=recurse(s.substr(1),ump);
        vector<string> res;
        
        for(int i=0;i<ump[s[0]].length();i++)
        {
                string a="";
                a+=ump[s[0]][i];
                for(int j=0;j<res1.size();j++)
                {
                    a+=res1[j];
                    res.push_back(a);
                    a=ump[s[0]][i];
                }
                
                
        }
        return res;
        
        
    }
};