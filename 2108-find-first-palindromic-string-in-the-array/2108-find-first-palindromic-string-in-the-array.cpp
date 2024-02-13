class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto x:words)
        {
            if(ispalindrom(x)) return x;
        }
        return "";
        
    }
    bool ispalindrom(string s)
    {
        int i=0;
        int j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};