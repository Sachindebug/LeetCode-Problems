class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& nums) {
        int res=0;
        int p=nums.size();
        long long int x = pow(2,p);
        for(int i=0;i<x;i++)
        {
            vector<int> ump(n,0);
            int count=0;
            for(int j=0;j<p;j++)
            {
                if((1<<j) & i)
                {
                    ump[nums[j][0]]++;
                    ump[nums[j][1]]--;
                    count++;
                }
            }
            
            bool ispossible = true;
            for(auto x:ump)
            {
                if(x) ispossible=false;
            }
            if(ispossible) res=max(res,count);
            
        }
        return res;
    }
};