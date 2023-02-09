class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i]+nums[i-1])
            {
                nums[i]+=nums[i-1];
               
            }
             res=max(nums[i],res);
        }
        return res;
    }
};