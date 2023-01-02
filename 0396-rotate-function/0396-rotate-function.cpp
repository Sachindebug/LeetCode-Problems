class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0;
        for(auto x:nums)
        {
            sum+=x;
        }
        int sum1=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum1+=(i*nums[i]);
        }
        int i=n-1;
        int res=sum1;
        while(i>=0)
        {
            sum1-=(nums[i]*(n-1));
            sum1+=(sum-nums[i]);
            res=max(res,sum1);
            i--;
        }
        return res;
    }
};