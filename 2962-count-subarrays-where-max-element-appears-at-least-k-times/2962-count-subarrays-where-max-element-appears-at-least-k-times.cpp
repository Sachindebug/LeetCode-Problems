class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        int n = nums.size();
        int i = 0, j=0;
        int mx = *max_element(nums.begin(),nums.end());
        int count = 0;
        while(j<nums.size())
        {
            if(nums[j]==mx) count++;
            while(count>=k)
            {
                if(nums[i]==mx) count--;
                res += 1ll*(n-j);
                i++;
            }
            j++;
        }
        return res;
    }
};