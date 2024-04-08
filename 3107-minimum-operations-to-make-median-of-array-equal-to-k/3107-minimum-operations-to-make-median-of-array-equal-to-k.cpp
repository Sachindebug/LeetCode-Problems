class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int medianIndex = n/2;
        long long ans = 0;
        if(nums[medianIndex]==k)
        {
            return 0;
        }
        if(nums[medianIndex]>k)
        {
            for(int i=0;i<=medianIndex;i++)
            {
                if(nums[i]>k)
                {
                    ans+=1ll*(nums[i]-k);
                }
            }
        }
        if(nums[medianIndex]<k)
        {
            for(int i=n-1;i>=medianIndex;i--)
            {
                if(nums[i]<k)
                {
                    ans+=1ll*(k-nums[i]);
                }
            }
        }
        return ans;
        
    }
};