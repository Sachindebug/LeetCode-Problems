class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n=words.size();
        vector<unordered_set<char>> s(n);
        for(int i=0;i<n;i++)
        {
            for(auto y:words[i]) 
            {
                s[i].insert(y);
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j]) count++;
            }
        }
        return count;
    }
};