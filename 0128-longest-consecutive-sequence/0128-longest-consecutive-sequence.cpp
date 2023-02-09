class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return n;
        sort(nums.begin(),nums.end());
        int prev=nums[0];
        int j=1;
        int res=0;
        int count=1;
        while(j<n)
        {
            if(nums[j]==prev) 
            {
                prev=nums[j];
                j++;
            }
            else if(nums[j]==prev+1)
            {
                count++;
                prev=nums[j];
                j++;
            }
            else
            {
                count=1;
                prev=nums[j];
                j++;
            }
            res=max(res,count);
            
        }
        res=max(res,count);
        return res;
    }
};