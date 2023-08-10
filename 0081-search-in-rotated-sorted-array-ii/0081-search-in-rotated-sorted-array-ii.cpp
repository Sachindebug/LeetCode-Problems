class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m]==target) return true;
            if(nums[l]<nums[m])
            {
                if(target>=nums[l] && target<nums[m])
                {
                    r=m;
                }
                else
                {
                    l=m+1;
                }
            }
            else if(nums[m]<nums[l])
            {
                if(target>nums[m] && target<nums[l])
                {
                    l=m+1;
                }
                else
                {
                    r=m;
                }
                
            }
            else
            {
                l++;
            }
        }
        return false;
    }
};