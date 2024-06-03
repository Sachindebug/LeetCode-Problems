class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;
        while(i<s.length() && j<t.length())
        {
            j+=(s[i]==t[j]);
            i++;
        }
        return t.length()-j;
    }
};