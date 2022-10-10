class Solution {
public:
    string breakPalindrome(string s) {
        if(s.length()==1)
        {
            return "";
        }
        int n=s.length();
        int center;
        if(n%2) center=n/2;
        bool found=false;
        for(int i=0;i<n;i++)
        {
            if(s[i]>'a' && i!=center)
            {
                s[i]='a';
                found=true;
                break;
            }
        }
        if(!found)
        {
            s[n-1]='b';
        }
        return s;
        
        
    }
};