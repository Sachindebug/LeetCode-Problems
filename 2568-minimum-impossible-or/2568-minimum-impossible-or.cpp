class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<32;i++)
        {
            int x=1<<i;
            if(!binary_search(nums.begin(),nums.end(),x))
            {
                return x;
            }
        }
        return 1<<32;
    }
};