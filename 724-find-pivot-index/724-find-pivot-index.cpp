class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        
        int n=nums.size();
        for(auto x:nums)
        {
            sum+=x;
        }
        int left=0;
        for(int i=0;i<n;i++)
        {
            if(left==sum-left-nums[i])
            {
                return i;
            }
            left+=nums[i];
        }
        return -1;
    }
};