class Solution {
public:
    bool isPossible(vector<int> &nums, int k){
        for(int i = 0;i<nums.size()-1;i++){
            int ele = nums[i];
            if(ele>=k*2) return true;
            if(nums[i]>=k && nums[i+1]>=k) return true;
        }
        int last = nums.back();
        if(last>=k*2) return true;
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n/2;
        int ans = -1;
        vector<int> arr;
        int count=1;
        for(int i = 1;i<n;i++){
            if(nums[i]>nums[i-1]) count++;
            else{
                arr.push_back(count);
                count=1;
            }
        }
        arr.push_back(count);
        while(l<=r){
            int m = l+(r-l)/2;
            if(isPossible(arr,m)){
                ans = m;
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
    }
};