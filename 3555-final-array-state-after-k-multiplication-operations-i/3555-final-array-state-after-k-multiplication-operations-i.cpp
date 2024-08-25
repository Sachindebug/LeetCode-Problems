class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--){
            int idx = minIdx(nums);
            nums[idx] = nums[idx]*multiplier; 
        }
        return nums;
    }
    int minIdx(vector<int> &nums){
        int ans = INT_MAX;
        int idx = -1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]<ans){
                ans = nums[i];
                idx = i;
            }
        }
        return idx;
    }
};