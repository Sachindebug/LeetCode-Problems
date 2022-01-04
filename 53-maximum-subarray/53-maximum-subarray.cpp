class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int res=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]+nums[i-1]>nums[i])
            {
                nums[i]=nums[i-1]+nums[i];
                
            }
            if(nums[i]>res)
            {
                    res=nums[i];
            }
        }
        return res;
        
    }
};