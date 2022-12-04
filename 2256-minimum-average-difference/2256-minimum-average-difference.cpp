class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int sum=0;
        int n=nums.size();
        if(n==1) return 0;
        for(auto x:nums)
        {
            sum+=x;
        }
        long long int sum1=0;
        int res=0;
        int ans=INT_MAX;
        for(int i=0;i<n-1;i++)
        {
            sum1+=nums[i];
            sum-=nums[i];
            int x=sum1/(i+1);
            int y=sum/(n-i-1);
            if(abs(x-y)<ans)
            {
                ans=abs(x-y);
                res=i;
            }
        }
        if(((sum1+sum)/n)<ans)
            return n-1;
        
        return res;
    }
};