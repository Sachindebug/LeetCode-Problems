class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> words;
        unordered_map<int,int> dp;
        for(int i=0;i<s.length();i++)
        {
            dp[i]=-1;
        }
        for(auto x:wordDict) words.insert(x);
        int idx=0;
        return recurse(s,idx,words,dp);
    }
    bool recurse(string &s,int idx,set<string> &words,unordered_map<int,int> &dp)
    {
        if(idx==s.length()) return true;
        if(dp[idx]!=-1) return dp[idx];
        string t="";
        bool res=false;
        for(int i=idx;i<s.length();i++)
        {
            t+=s[i];
            if(words.find(t)!=words.end())
            {
                res=res || recurse(s,i+1,words,dp);
            }
        }
        if(res) dp[idx]=1;
        else dp[idx]=0;
        return res;
    }
};