class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> ump;
        int sum=0;
        int count=0;
        ump[0]++;
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