class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res=INT_MIN;
        for(int i=0;i<accounts.size();i++)
        {
            int x=accumulate(accounts[i].begin(),accounts[i].end(),0);
            res=max(res,x);
        }
        return res;
        
    }
};