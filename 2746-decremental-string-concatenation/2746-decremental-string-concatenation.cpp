class Solution {
public:
    map<vector<int>,int> dp;
    int solve(vector<string>& words,int idx,char first,char last){
        if(idx==words.size()){
            return 0;
        }
        if(dp.count({idx,first,last})) return dp[{idx,first,last}];
        string curr = words[idx];
        int sz = curr.size();
        int op1 = 0,op2 = 0;
        if(last==curr[0]) op1 += (sz-1);
        else op1 += sz;
        op1 += solve(words,idx+1,first,curr[sz-1]);
        if(first==curr[sz-1]) op2 += (sz-1);
        else op2 += sz;
        op2 += solve(words,idx+1,curr[0],last);
        return dp[{idx,first,last}] = min(op1,op2);
    }
    
    int minimizeConcatenatedLength(vector<string>& words) {
        dp.clear();
        int n = words.size();
        int sz = words[0].size();
        return words[0].size()+solve(words,1,words[0][0],words[0][sz-1]);
    }
};