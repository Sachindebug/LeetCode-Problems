class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        recurse(s,0,temp,res);
        return res;
    }
    void recurse(string &s,int idx,vector<string> &temp,vector<vector<string>> &res)
    {
        if(idx==s.length())
        {
            res.push_back(temp);
        }
        string t="";
        for(int i=idx;i<s.length();i++)
        {
            t+=s[i];
            if(ispalindrome(t))
            {
                temp.push_back(t);
                recurse(s,i+1,temp,res);
                temp.pop_back();
            }
        }
    }
    bool ispalindrome(string s)
    {
        int i=0;
        int j=s.length()-1;
        while(j>=i)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
        
        
};