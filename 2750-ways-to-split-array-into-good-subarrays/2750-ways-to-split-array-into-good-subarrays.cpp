class Solution {
public:
    int mod=1000000007;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n=nums.size();
        long long int ans=1;
        long long int count=0;
        int prev=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) count++;
            else
            {
                if(prev!=-1)
                {
                    ans=ans*(count+1);
                    ans=ans%mod;
                }
                count=0;
                prev=i;
            }
            count%=mod;
           
        }
        if(count==n) return 0;
        if(ans==0) return 1;
        return ans;
    }
};