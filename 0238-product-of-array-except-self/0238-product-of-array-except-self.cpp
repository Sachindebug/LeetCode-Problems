class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count=0;
        int product=1;
        for(auto x:nums)
        {
            if(x==0)
            {
                count++;
            }
            else
            {
                product*=x;
            }
        }
        if(count==0)
        {
            for(int i=0;i<nums.size();i++)
            {
                nums[i]=product/nums[i];
            
            
            }
            
        }
        else if(count==1)
        {
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==0)
                {
                    nums[i]=product;
                }
                else
                {
                    nums[i]=0;
                }   
            }
            
        }
        else
        {
            for(int i=0;i<nums.size();i++)
            {
                nums[i]=0;
            }
            
        }
        return nums;
        
        
    }
};