class Solution {
public:
    char findTheDifference(string s, string t) {
        char res=0;
        for(int i=0;i<s.length();i++)
        {
            res=res^s[i];
        }
        for(int i=0;i<t.length();i++)
        {
            res=res^t[i];
        }
        return res;
    }
};