class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string> s(bannedWords.begin(),bannedWords.end());  
        int count = 0;
        for(auto x: message) count+=(s.find(x)!=s.end());
        return count>=2;
    }
};