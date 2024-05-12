class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> sPos(26,-1);
        vector<int> tPos(26,-1);
        for(int i=0;i<s.length();i++)
        {
            sPos[s[i]-'a'] = i;
            tPos[t[i]-'a'] = i;
        }
        int res = 0;
        for(int i =0 ;i<26;i++)
        {
            if(sPos[i]!=-1)
            {
                res+=abs(sPos[i]-tPos[i]);
            }
        }
        return res;
    }
};