class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for(int i=0;i<words.size();i++)
        {
            if(contains(words[i],x)) res.push_back(i);
        }
        return res;
    }
    bool contains(string s, char c)
    {
        for(auto x:s) if(x==c) return true;
        return false;
    }
};