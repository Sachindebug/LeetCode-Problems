class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n=nums.size();
        long long sum=nums[n-1],res=sum;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<=sum)
            {
                sum+=(long long int )nums[i];
            }
            else
            {
                res=max(res,sum);
                sum=nums[i];
            }
        }
        res=max(res,sum);
        return res;
    }
};