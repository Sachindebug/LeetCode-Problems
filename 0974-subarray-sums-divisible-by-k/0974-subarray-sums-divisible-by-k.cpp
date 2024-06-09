class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return 0;
        unordered_map<int,int> ump;
        ump[0]=1;
        int i=0;
        int curr_sum=0;
        int count=0;
        while(i<n)
        {
            curr_sum+=nums[i];
            int rem=curr_sum%k;
            if(rem<0) rem+=k;
            if(ump.find(rem)!=ump.end())
            {
                count+=ump[rem];
            }
            ump[rem]++;
            i++;
        }
        return count;
        
    }
};