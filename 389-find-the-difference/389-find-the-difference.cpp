class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> ump;
        for(auto x:t)
        {
            ump[x]++;
        }
        for(auto x:s)
        {
            ump[x]--;
        }
        for(auto x:ump)
        {
            if(x.second>0) return x.first;
        }
        return t[0];
    }
};