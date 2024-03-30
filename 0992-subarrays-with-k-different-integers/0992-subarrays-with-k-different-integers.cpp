class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return tempFun(nums,k)-tempFun(nums,k-1);
    }
    int tempFun(vector<int>& nums, int k)
    {
        map<int,int> ump;
        int i=0;
        int j=0;
        int ans = 0;
        while(j<nums.size())
        {
            ump[nums[j]]++;
            while(ump.size()>k)
            {
                ump[nums[i]]--;
                if(ump[nums[i]]==0) ump.erase(nums[i]);
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};