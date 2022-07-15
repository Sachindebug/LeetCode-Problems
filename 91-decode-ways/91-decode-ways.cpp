class Solution {
public:
    int numDecodings(string s) {
        unordered_map<string,char> ump;
        for(int i=0;i<26;i++)
        {
            string p=to_string(i+1);
            ump[p]='A'+i;
        }
        vector<int> dp(s.length()+1,-1);
        return recurse(s,ump,0,dp);
        
    }
    int recurse(string &s,unordered_map<string,char> &ump,int idx,vector<int> &dp)
    {
        if(idx>=s.length()) return 1;
        if(dp[idx]!=-1) return dp[idx];
        int res=0;
        string t="";
        for(int i=idx;i<s.length();i++)
        {
            t+=s[i];
            
            if(ump.find(t)!=ump.end())
            {
                
                res+=recurse(s,ump,i+1,dp);
            }
        }
        return dp[idx]=res;
    }
};