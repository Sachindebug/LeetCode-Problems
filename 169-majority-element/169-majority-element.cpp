class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=nums[0];
        int n=nums.size();
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==res) count++;
            else count--;
            if(count==0)
            {
                count=1;
                res=nums[i];
            }
        }
        return res;
    }
};