class Solution {
public:
    int bitCount(int n)
    {
        return __builtin_popcount(n);
    }
    bool canSortArray(vector<int>& nums) {
        int i=0;
        int count = bitCount(nums[i]);
        int j=1;
        while(j<nums.size())
        {
            if(bitCount(nums[j])==count) j++;
            else
            {
                sort(nums.begin()+i,nums.begin()+j);
                count = bitCount(nums[j]);
                i=j;
                j++;
            }
        }
        sort(nums.begin()+i,nums.begin()+j);
        return is_sorted(nums.begin(),nums.end());
    }
};