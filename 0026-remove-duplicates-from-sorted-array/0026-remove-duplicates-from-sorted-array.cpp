class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n=nums.size();
        if(n<=1) return n;
        int i=1;
        int j=0;
        while(j<n-1)
        {
           if(nums[j]!=nums[j+1])
           {
               nums[i]=nums[j+1];
               i++;
           }
            j++;
        }
        return i;
    }
};