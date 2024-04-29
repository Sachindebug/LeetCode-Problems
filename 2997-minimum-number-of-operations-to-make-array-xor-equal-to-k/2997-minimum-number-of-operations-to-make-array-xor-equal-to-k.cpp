class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> bitCount(32,0);
        for(int i=0;i<32;i++)
        {
            for(int j = 0;j<nums.size();j++)
            {
                if((1<<i) & nums[j])
                {
                    bitCount[i]++;
                }
            }
        }
        int res = 0;
        for(int i = 0;i<32;i++)
        {
            if((1<<i) & k)
            {
                if(bitCount[i]%2==0) res++;
            }
            else
            {
                if(bitCount[i]%2==1) res++;
            }
        }
        return res;
    }
};