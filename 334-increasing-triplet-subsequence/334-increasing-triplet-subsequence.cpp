class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n);
        left[0]=nums[0];
        int mn=left[0];
        for(int i=1;i<n;i++)
        {
            mn=min(mn,nums[i]);
            left[i]=mn;
        }
        vector<int> right(n);
        right[n-1]=nums[n-1];
        int mx=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            mx=max(mx,nums[i]);
            right[i]=mx;
        }
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]>left[i] && nums[i]<right[i]) return true;
        }
        return false;
        
    }
};