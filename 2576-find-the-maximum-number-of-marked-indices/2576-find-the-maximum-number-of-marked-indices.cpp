class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1) return 0;
        int j=n-1;
        int i=(n/2)-1;
        int count=0;
        while(i>=0 && j>=0)
        {
            if(nums[i]*2<=nums[j])
            {
                count+=2;
                i--;
                j--;
            }
            else
            {
                i--;
            }
        }
        return count;
    }
};