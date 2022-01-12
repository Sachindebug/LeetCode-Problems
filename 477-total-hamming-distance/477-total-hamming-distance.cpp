class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int count1=0;
            int count0=0;
            for(int j=0;j<n;j++)
            {
                if(nums[j]&(1<<i)) count1++;
                else count0++;
            }
            ans+=(count0*count1);
        }
        return ans;
    }
};