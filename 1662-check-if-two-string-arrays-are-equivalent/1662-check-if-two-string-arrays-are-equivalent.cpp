class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string x="";
        string t="";
        for(auto it:word1) x+=it;
        for(auto it:word2) t+=it;
        return x==t;

    }
};