class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res=recurse(s,0);
        return res;
    }
    vector<string> recurse(string s,int idx)
    {
        
        if(idx==s.length()-1)
        {
            vector<string> res;
            char c=s[idx];
            if(isalpha(c))
            {
                
            
                string temp="";
                if(c<96)
                {
                    c+=32;
                }
                temp+=c;
                
                res.push_back(temp);
                temp="";
                c-=32;
                temp+=c;
                
                res.push_back(temp);
                
             }
            else
            {
                string temp="";
                temp+=s[idx];
                res.push_back(temp);
            }
            return res;
            
        }
            
        
        vector<string> res1=recurse(s,idx+1);
        char c=s[idx];
        vector<string> res;
        if(isalpha(c))
        {
            for(int i=0;i<res1.size();i++)
            {
                string temp="";
                if(c<96)
                {
                    c+=32;
                }
                temp+=c;
                temp+=res1[i];
                res.push_back(temp);
                temp="";
                c-=32;
                temp+=c;
                temp+=res1[i];
                res.push_back(temp);
                
            }
            
        }
        else
        {
            for(int i=0;i<res1.size();i++)
            {
                string temp="";
                temp+=c;
                temp+=res1[i];
                res.push_back(temp);
                
            }
            
        }
        return res;
    }
};