class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums)
        {
            sum+=x;
        }
        int sum1=0;
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            int a=i;
            int b=n-i;
            int x=0;
            x+=(a*nums[i]-sum1);
            x+=(sum-nums[i]*b);
            res.push_back(x);
            sum1+=nums[i];
            sum-=nums[i];
        }
        return res;
    }
};