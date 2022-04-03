class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        res.push_back(nums);
        vector<int> temp=nextPermutation(nums);
        while(temp!=nums)
        {
            res.push_back(temp);
            temp=nextPermutation(temp);
        }
        return res;
    }
    vector<int> nextPermutation(vector<int>& temp) {
        vector<int> nums=temp;
        int i=nums.size()-2;
        while(i>=0 && nums[i+1]<=nums[i])
        {
            i--;
        }
        if(i>=0)
        {
            int j=nums.size()-1;
            while(nums[j]<=nums[i])
            {
                j--;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
        return nums;
    }
};