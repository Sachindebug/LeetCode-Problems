class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        for(int i = 0;i<k-1;i++) nums.push_back(nums[i]);
        int n = nums.size();
        int prev = 0;
        int nxt = 1;
        int ans = 0;
        while(nxt<n){
            if(nums[nxt]==nums[nxt-1]){
                prev = nxt;
            }
            if(nxt-prev+1==k){
                ans++;
                prev++;
            }
            nxt++;
        }

        return ans;
    }
};