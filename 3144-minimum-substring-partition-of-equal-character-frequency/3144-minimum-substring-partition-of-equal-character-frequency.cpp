class Solution {
public:
    bool isValid(vector<int> &freq, int max_count) {
        for(int f: freq) {
            if(f!=0 && f!=max_count)
                return false;
        }
        
        return true;
    }
    
    int helper(string s, int idx, int count, vector<int> &dp) {
        if(idx==s.size()) return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        vector<int> freq(26);
        int max_count=0, res=INT_MAX;
        
        for(int i=idx; i<s.size(); i++) {
            freq[s[i]-'a']++;
            max_count = max(max_count, freq[s[i]-'a']);
            
            if(isValid(freq, max_count)) {
                res = min(res, 1 + helper(s, i+1, count+1, dp));
            }
        }
        
        return dp[idx] = res;
    }
    
    int minimumSubstringsInPartition(string s) {
        vector<int> dp(s.size()+1, -1);
        
        return helper(s, 0, 1, dp);
    }
};