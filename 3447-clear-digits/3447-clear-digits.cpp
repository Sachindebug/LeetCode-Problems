class Solution {
public:
    string clearDigits(string s) {
        string res="";
        for(int i =0;i<s.length();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                res+=s[i];
            }
            else
            {
                char c = res[res.length()-1];
                if(c>='a' && c<='z')
                {
                    res.pop_back();
                }
            }
        }
        return res;
    }
};