class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int j = 2;
        int count = 0;
        while(j<nums.size()){
            count+=(2*(nums[j]+nums[j-2])==nums[j-1]);
            j++;
        }
        return count;
    }
};