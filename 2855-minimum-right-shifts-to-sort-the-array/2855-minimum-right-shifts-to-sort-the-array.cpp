class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int res = -1;
        int  n = nums.size();
        if(n == 1) return 0;
        
        for(int i=0; i<n; i++) {
            if(nums[i] > nums[(i+1) % n]) {
                if(res == -1) {
                    res = i + 1;
                }else{
                    return -1;
                }
            }
        }
        
        return n - res;
    }
};