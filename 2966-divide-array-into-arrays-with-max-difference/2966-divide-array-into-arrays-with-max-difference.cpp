class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i = 0;i<nums.size()-2;i+=3)
        {
            cout<<nums[i]<<" ";
            if(nums[i+1]-nums[i] > k || nums[i+2]-nums[i] > k) return {};
            res.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        return res;
    }
};