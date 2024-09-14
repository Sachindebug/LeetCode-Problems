class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int x=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int res=INT_MIN;
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1] && nums[i]==x)
            {
                count++;
            }
            else
            {
                res=max(res,count);
                count=1;
                
            }
        }
        
        res=max(res,count);
        return res;
    }
};