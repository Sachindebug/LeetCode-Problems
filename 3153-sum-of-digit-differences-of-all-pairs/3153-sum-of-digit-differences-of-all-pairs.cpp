class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<map<int,int>> ump(10);
        long long ans = 0;
        for(int i = 0;i<nums.size();i++)
        {
            int x = nums[i];
            int count = 0;
            while(x>0)
            {
                int rem = x%10;
                x=x/10;
                count++;
                int diff = i-ump[count][rem];
                ans+=1ll*diff;
                ump[count][rem]++;
            }
        }
        return ans;
    }
};