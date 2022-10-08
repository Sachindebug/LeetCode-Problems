class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                string s=nums[i]+nums[j];
                if(i!=j && s==target) count++;

            }
        }
        return count;
    }
};