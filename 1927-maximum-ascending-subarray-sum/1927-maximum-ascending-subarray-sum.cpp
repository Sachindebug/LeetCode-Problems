class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum=0;
        int mx=0;
        if(nums.size()==1)
        {
            return nums[0];
        }
        sum=nums[0];
        int prev=0;
    
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[prev])
            {
                sum+=nums[i];
            }
            else
            {
                mx=max(mx,sum);
                sum=nums[i];
                
            }
            prev=i;
        }
        mx=max(mx,sum);
        
        return mx;
    }
};