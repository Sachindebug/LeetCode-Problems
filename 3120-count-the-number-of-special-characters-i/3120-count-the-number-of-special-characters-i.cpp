class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int> ump;
        for(auto x:word) ump[x]++;
        int count = 0;
        for(auto x:ump)
        {
            char c = x.first;
            if(c>90)
            {
                if(ump.find(c-32)!=ump.end()) count++;
            }
        }
        return count;
    }
};