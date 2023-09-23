class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string odds1="";
        string odds2="";
        string evens1="";
        string evens2="";
        for(int i=0;i<s1.length();i++)
        {
            if(i%2) odds1+=s1[i];
            else evens1+=s1[i];
        }
        for(int i=0;i<s2.length();i++)
        {
            if(i%2) odds2+=s2[i];
            else evens2+=s2[i];
        }
        sort(odds1.begin(),odds1.end());
        sort(odds2.begin(),odds2.end());
        sort(evens1.begin(),evens1.end());
        sort(evens2.begin(),evens2.end());
        return (odds1==odds2 && evens1==evens2);
    }
};