class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=n-2;
        while(i>=1)
        {
            
            int a=nums[i];
            int b=nums[i-1];
            int c=nums[i+1];
            if(a+b>c)
            {
                return a+b+c;
            }
            i--;
            
        }
        
        return 0;
    }
};