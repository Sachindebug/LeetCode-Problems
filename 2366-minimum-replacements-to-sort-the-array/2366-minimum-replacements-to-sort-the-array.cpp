class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        long long res = nums[n-1];
        if(n==1) return 0;
        for(int i=n-2;i>=0;i--)
        {
            int noOfTime=nums[i]/res;   
            if((nums[i])%res!=0){
                noOfTime++;
                res=nums[i]/noOfTime;
            }   
            sum+=noOfTime-1;
        }
        return sum;
    }
};