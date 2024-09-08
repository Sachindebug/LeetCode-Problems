class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans=0;
        int start=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>nums[start]){
                ans+=(i-start)*1LL*nums[start];
                start=i;
            }
        }
        ans+=(n-1-start)*1LL*nums[start];
        return ans;        
    }
};