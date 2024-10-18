class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int res=0;
        for(auto x:nums) res=res|x;
        return recurse(nums,0,res,0);
    }
    int recurse(vector<int> &nums,int idx,int x,int count)
    {
        if(idx==nums.size()) return count==x;
        return recurse(nums,idx+1,x,count)+recurse(nums,idx+1,x,count|nums[idx]);
    }
};