class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> ump;
        ump[0]++;
        int sum=0;
        int count=0;
        for(auto x:nums)
        {
            sum+=x;
            if(ump.find(sum-k)!=ump.end())
            {
                count+=ump[sum-k];
            }
            ump[sum]++;
        }
        return count;
    }
};