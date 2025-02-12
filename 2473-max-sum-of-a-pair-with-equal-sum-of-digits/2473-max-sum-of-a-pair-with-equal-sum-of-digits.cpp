class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>> ump;
        for(auto x:nums)
        {
            int sum=getSum(x);
            ump[sum].push_back(x);
        }
        int res=-1;
        for(auto x:ump)
        {
            sort(x.second.begin(),x.second.end(),greater<int>());
            if(x.second.size()<2) continue;
            else
            {
                res=max(res,x.second[0]+x.second[1]);
            }
        }
        return res;
    }
    int getSum(int n)
    {
        int sum=0;
        while(n>0)
        {
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
};