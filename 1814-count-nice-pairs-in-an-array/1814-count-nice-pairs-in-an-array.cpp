class Solution {
public:
    int reverse(int n)
    {
        int res=0;
        while(n>0)
        {
            res*=10;
            res+=(n%10);
            n/=10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> ump;
        int mod=1e9+7;
        for(auto x:nums)
        {
            int y=reverse(x);
            ump[x-y]++;
        }
        long long int res=0;
        for(auto x:ump)
        {
            long long int t=x.second;
            res+=(t*(t-1)/2);
            res%=mod;
        }
        return res;
    }
};