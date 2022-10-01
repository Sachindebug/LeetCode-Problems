class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> ump;
        int sum=0;
        int count=0;
        ump[sum]++;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            count+=ump[sum-goal];
            ump[sum]++;
        }
        return count;
    }
    
};