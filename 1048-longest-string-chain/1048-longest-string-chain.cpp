class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(), [](const std::string& a, const std::string& b) {
            return a.size() < b.size();
        });
        int n = words.size();
        vector<vector<int>> dp(n+1,vector<int>(n+2,-1));
        return recurse(words,0,-1,dp);
    }
    bool isSub(string &s,string &t)
    {
        int i=0;
        int j=0;
        while(i<s.length() && j<t.length())
        {
            if(s[i]==t[j])
            {
                j++;
                i++;
            }
            else
            {
                j++;
            }
        }
        return i==s.length();
    }
    int recurse(vector<string>& words, int curr, int prev,vector<vector<int>> &dp)
    {
        if(curr==words.size()) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        int res=0;
        if(prev==-1 or (words[prev].length()+1==words[curr].length() and isSub(words[prev],words[curr])))
        {
            res = max(res,1+recurse(words,curr+1,curr,dp));
        }
        res = max(res,recurse(words,curr+1,prev,dp));
        return dp[curr][prev+1]=res;
    }
};