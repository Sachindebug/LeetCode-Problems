class Solution {
public:
    bool halvesAreAlike(string s) {
        int a = 0;
        int b = 0;
        int i = 0;
        int j = s.length()-1;
        while(i<j)
        {
            if(isVowel(s[i])) a++;
            if(isVowel(s[j])) b++;
            i++;
            j--;
        }
        return a==b;
    }
    bool isVowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U') return true;
        return false;
    }
};