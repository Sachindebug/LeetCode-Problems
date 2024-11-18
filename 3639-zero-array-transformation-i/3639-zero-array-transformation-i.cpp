class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> freq(n+1,0);
        for(auto x:queries){
            int l = x[0];
            int r = x[1];
            freq[l]-=1;
            freq[r+1]+=1;
        }
        int sum = 0;
        for(int i = 0 ;i<nums.size();i++){
            sum+=freq[i];
            nums[i]+=sum;
            cout<<nums[i]<<" ";
            if(nums[i] > 0) return false;
        }
        return true;
    }
};