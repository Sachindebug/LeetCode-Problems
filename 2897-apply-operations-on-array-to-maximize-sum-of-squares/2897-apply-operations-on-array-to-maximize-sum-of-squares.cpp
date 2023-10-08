class Solution {
public:
    int mod = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector <int> bits(32, 0);
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 32; j++)
            {
                bits[j] += (nums[i] >> j) & 1;
            }
        }
        long long ans = 0;
        while(k--)
        {
            long long temp = 0;
            for(long long i = 0; i < 32; i++)
            {
                if(bits[i] > 0)
                {
                    temp = (1 << i) | temp;
                    bits[i]--;
                }
            }
            temp = (temp * temp) % mod;
            ans = (ans + temp) % mod;
        }
        return ans;
    }
};