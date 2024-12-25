class Solution {
public:
    int check(vector<int>& nums,int n, int t, int m){
        int l = lower_bound(nums.begin(), nums.end(), n) - nums.begin();
        int h = upper_bound(nums.begin(), nums.end(), n) - nums.begin();
        int ll = lower_bound(nums.begin(), nums.end(), n-t) - nums.begin();
        int hh = upper_bound(nums.begin(), nums.end(), n+t) - nums.begin();
        int res = (hh - h) + (l - ll);
        return min(m,res) + (h-l);
    }
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int m = numOperations;
        sort(nums.begin(), nums.end());
        int ans = 1;
        for(int i=nums[0]; i<=nums[nums.size()-1]; i++){
            ans = max(check(nums,i,k,m), ans);
        }
        return ans;
    }
};