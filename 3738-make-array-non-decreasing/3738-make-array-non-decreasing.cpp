class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int prev = nums[0];
        int count = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]>=prev){
                prev = nums[i];
                count++;
            }
        }
        return count;
    }
};