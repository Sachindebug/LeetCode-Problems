class Solution {
public:
    int chalkReplacer(vector<int>& nums, int k) {
        long long int sum = 0;
        for(auto x: nums){
            sum+=(1ll*x);
        }
        k = k%sum;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>k) return i;
            k-=nums[i];
        }
        return 0;
    }
};