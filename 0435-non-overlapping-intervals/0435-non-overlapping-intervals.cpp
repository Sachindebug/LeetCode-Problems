class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),[](vector<int> &a, vector<int> &b){
            if(a[1]==b[1]) return a[0]<b[0];
            else return a[1]<b[1];
        });
        vector<int> prev = nums[0];
        int count = 0;
        for(int i = 1;i<nums.size();i++){
            vector<int> curr = nums[i];
            int a = prev[0];
            int b = prev[1];
            int c = curr[0];
            int d = curr[1];
            if(b<=c) {
                prev = curr;
            }
            else if((c<=a && b<d) || c<=b){
                count++;
            }
        }
        return count;
    }
};