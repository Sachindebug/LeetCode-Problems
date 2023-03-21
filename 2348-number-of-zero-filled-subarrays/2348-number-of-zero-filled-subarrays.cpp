class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int count=0;
        long long int res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                count++;
            }
            else
            {
                res+=((count*(count+1))/2);
                count=0;
            }
        }
        res+=((count*(count+1))/2);

        return res;
    }
};