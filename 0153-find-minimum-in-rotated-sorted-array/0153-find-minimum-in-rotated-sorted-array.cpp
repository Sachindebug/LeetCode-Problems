class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int l=0;
        int r=nums.size()-1;
        while(l<r)
        {
            if(nums[l]<nums[r]) return nums[l];
            int m=(r+l)/2;
            if(nums[m]>=nums[l])
            {
                l=m+1;
            }
            else
            {
               r=m;
            }
        }
        return nums[l];
    }
};