class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int sum=0;
        for(auto x:nums) sum+=x;
        int count=0;
        long long int sum1=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            sum1+=nums[i];
            sum-=nums[i];
            count+=(sum1>=sum);
        }
        return count;
        
    }
};