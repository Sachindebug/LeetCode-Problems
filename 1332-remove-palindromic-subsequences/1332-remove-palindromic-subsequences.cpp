class Solution {
public:
    bool ispalindrom(string s)
    {
        int i=0;
        int j=s.length()-1;
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(ispalindrom(s)) return 1;
        else return 2;
    }
};