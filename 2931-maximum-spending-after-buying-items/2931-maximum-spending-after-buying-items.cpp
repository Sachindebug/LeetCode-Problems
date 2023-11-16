class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        vector<long long> op;
        
        for(long long  i=0;i<values.size();i++)
        {
            for(long long j=0;j<values[i].size();j++)
            {
                op.push_back(values[i][j]);
            }
        }
      
        sort(op.begin(),op.end());
        
        long long sum = 0;
        
        for(int i=0;i<op.size();i++)
        {
            sum+=(op[i]*(i+1));
        }
        
        return sum;
    }
};