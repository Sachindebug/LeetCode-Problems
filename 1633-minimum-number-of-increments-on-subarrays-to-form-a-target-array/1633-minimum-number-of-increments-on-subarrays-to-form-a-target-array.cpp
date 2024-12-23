class Solution {
public:
    int minNumberOperations(vector<int>& nums) {
        int mn = 0;
        int res = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]>mn){
                res+=(nums[i]-mn);
            }
            mn = nums[i];
        }
        return res;
    }
};