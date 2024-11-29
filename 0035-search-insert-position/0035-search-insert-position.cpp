class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        if(target<nums[0]) return 0;
        if(target>nums[nums.size()-1]) return r+1;
        int res=-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m]>=target)
            {
                res=m;
                r=m-1;
            }
            else l=m+1;
        }
        return res;
    }
};