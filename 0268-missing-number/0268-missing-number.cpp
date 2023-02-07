class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        sum=accumulate(nums.begin(),nums.end(),sum);
        int n=nums.size();
        int sum1=n*(n+1)/2;
        return sum1-sum;
    }
};