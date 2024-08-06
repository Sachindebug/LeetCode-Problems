class Solution {
public:
    int minimumPushes(string word) {
        vector<int> value(26,0);
        for(auto x:word)
        {
            value[x-'a']++;
        }
        sort(value.begin(),value.end(),greater<int>());
        int count = 0;
        for(int i=0;i<26;i++)
        {
            count+=(((i/8)+1)*(value[i]));
        }
        return count;
    }
};