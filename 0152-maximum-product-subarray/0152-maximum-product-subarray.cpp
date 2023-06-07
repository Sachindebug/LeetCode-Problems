class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=nums[0];
        int mn=nums[0];
        int res=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            int t = max({nums[i],mx*nums[i],mn*nums[i]});
            mn=min({nums[i],mx*nums[i],mn*nums[i]});
            mx=t;
            res=max(res,mx);
        }
        return res;
        
    }
};