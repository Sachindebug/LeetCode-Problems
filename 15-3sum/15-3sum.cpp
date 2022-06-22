class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            else
            {
                int l=i+1;
                int r=n-1;
                while(l<r)
                {
                   int s=nums[i]+nums[l]+nums[r]; 
                   if(s>0) r--;
                   else if(s<0) l++;
                   else
                   {
                       res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                       while(l<r && nums[l]==nums[l+1]) l++;
                       while(r>l && nums[r]==nums[r-1]) r--; 
                       l++;
                       r--;
                   }
                }
                
            }
        }
        return res;
    }
};