class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        vector<int> arr;
        int count=1;
        int n = nums.size();
        for(int i = 1;i<n;i++){
            if(nums[i]>nums[i-1]) count++;
            else{
                arr.push_back(count);
                count=1;
            }
        }
        arr.push_back(count);
        for(int i = 0;i<arr.size()-1;i++){
            int ele = arr[i];
            if(ele>=k*2) return true;
            if(arr[i]>=k && arr[i+1]>=k) return true;
        }
        int last = arr.back();
        if(last>=k*2) return true;
        return false;
    }
};