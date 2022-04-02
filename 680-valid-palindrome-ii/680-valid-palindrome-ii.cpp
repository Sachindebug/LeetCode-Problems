class Solution {
public:
    bool validPalindrome(string s) {
        int l=-1,r=-1;
        int p=0;
        int q=s.length()-1;
        while(p<=q)
        {
            if(s[p]!=s[q])
            {
                l=p;
                r=q;
                break;
            }
            p++;
            q--;
        }
        if(l==-1 && r==-1) return true;
        string s1="";
        string s2="";
        for(int i=0;i<s.length();i++)
        {
            if(i==l) continue;
            else s1+=s[i];
        }
        cout<<s1<<endl;
        for(int i=0;i<s.length();i++)
        {
            if(i==r) continue;
            else s2+=s[i];
        }
        cout<<s2<<endl;
        return (ispalin(s1)||ispalin(s2));

        
    }
    bool ispalin(string s)
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
};