class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==i) continue;
            else
            {
                int count=0;
                    
                while(nums[i]!=i)
                {
                    if(nums[i]>=n) break;
                    else swap(nums[i],nums[nums[i]]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i) return i;
        }
        return n;
    }
};