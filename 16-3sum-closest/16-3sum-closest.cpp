class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int res=nums[0]+nums[1]+nums[2];
        int n=nums.size();
        
        for(int i=0;i<n-2;i++)
        {
            int l=i+1;
            int r=n-1;
            
            while(l<r)
            {
                int x=nums[i]+nums[l]+nums[r];
                if(abs(x-target)<abs(res-target))
                {
                    res=x;
                    
                }
                else if(target>x)
                {
                    l++;
                }
                else
                {
                    
                    r--;
                    
                }
            }
        }
        return res;
        
    }
};