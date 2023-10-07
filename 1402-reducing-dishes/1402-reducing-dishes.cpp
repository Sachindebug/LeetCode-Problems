class Solution {
public:
    int maxSatisfaction(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long res = 0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            long long ans = 0;
            for(int j=i;j<n;j++)
            {
                ans += (1ll*nums[j]*(j-i+1));
            }
            res=max(res,ans);
        }
        return res;
    }
};