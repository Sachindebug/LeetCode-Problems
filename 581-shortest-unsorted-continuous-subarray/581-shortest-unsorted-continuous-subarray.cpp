class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int lpos=-1;
        int rpos=-1;
        int lwrong=INT_MAX;
        int rwrong=INT_MIN;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {
                lwrong=min(lwrong,nums[i]);
                
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>lwrong)
            {
                lpos=i;
                break;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])
            {
                rwrong=max(nums[i],rwrong);
                
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<rwrong)
            {
                rpos=i;
                break;
            }
        }
        if(lpos==-1 || rpos==-1) return 0;
        return rpos-lpos+1;
    }
};