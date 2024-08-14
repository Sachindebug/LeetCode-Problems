class Solution {
public:

    int findNumberOfPairs(vector<int>& nums, int n, int d) {
        int l = 0, r = 1, count = 0;
        while(r < n) {
            if((nums[r] - nums[l]) <= d){
                count = count + (r - l);
                r++;
            } else{
                l++;
            }
            if(l == r) {
                r++;
            }
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, h = nums[n-1] - nums[0], ans = -1;
        while(l<=h) {
            int mid = l + (h - l) / 2;
            int p = findNumberOfPairs(nums, n, mid);
            if(p >= k){
                ans = mid;
                h = mid -1 ;
            }else {
                l = mid + 1;
           }
       }
        return ans;
    
    }
};