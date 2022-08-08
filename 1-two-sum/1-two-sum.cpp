class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ump;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            ump[nums[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            if(ump.find(target-nums[i])!=ump.end() && ump[target-nums[i]]!=i)
            {
                return {i,ump[target-nums[i]]};
            }
        }
        return {-1};
    }
};