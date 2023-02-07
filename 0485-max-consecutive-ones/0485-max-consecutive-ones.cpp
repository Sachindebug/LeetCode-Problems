class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum=0;
        int res=0;
        for(auto x:nums)
        {
            if(x) sum++;
            else
            {
                res=max(res,sum);
                sum=0;
            }
        }
        res=max(res,sum);
        return res;
    }
};