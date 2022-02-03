class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int t) {
        int count=0;
        int sum=0;
        int res;
        int n=nums.size();
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        res=(sum)/(k);
        if(res>=t) count++;
        int start=0;
        for(int i=k;i<n;i++)
        {
            sum+=nums[i];
            sum-=nums[start];
            start++;
            res=(sum)/(k);
            if(res>=t) count++;
        }
        return count;
    }
};