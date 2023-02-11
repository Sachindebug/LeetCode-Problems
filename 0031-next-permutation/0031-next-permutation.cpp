class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return;
        int j=n-2;
        while(j>=0)
        {
            if(nums[j]<nums[j+1])
            {
                break;
            }
            j--;
        }
        if(j<0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int k=n-1;
        while(k>=0)
        {
            if(nums[k]>nums[j])
            {
                swap(nums[j],nums[k]);
                break;
            }
            k--;
        }
        reverse(nums.begin() + j + 1, nums.end());
    }
};