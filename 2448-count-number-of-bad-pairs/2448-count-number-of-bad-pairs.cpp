class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        long long res=(n*(n-1))/2;
        unordered_map<long long ,long long> ump;
        for(int i=0;i<n;i++)
        {
            ump[nums[i]-i]++;
        }
        for(auto x:ump)
        {
            res-=(x.second*(x.second-1))/2;
        }
        return res;
    }
};