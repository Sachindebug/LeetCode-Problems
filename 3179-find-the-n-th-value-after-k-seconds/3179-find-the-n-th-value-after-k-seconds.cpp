class Solution {
public:
    int MOD = 1000000007;
    int valueAfterKSeconds(int n, int k) {
        vector<int> nums;
        for(int i =0;i<n;i++) nums.push_back(1);
        for(int i = 0;i<k;i++)
        {
            for(int j =1;j<n;j++)
            {
                nums[j] = nums[j-1]+nums[j];
                nums[j]%=MOD;
            }
        }
        return nums[n-1];
    }
};