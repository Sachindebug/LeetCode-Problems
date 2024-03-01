class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count=0,n=s.length();
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1') count++;
        }
        string res = "";
        for(int i=0;i<n-1;i++)
        {
            if(count>1)
            {
                res+='1';
                count--;
            }
            else res+='0';
        }
        res+='1';
        return res;
    }
};