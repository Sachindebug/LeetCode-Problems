class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int> s;
        int sum=0;
        int res=0;
        int n=nums.size();
        int l=0,r=0;
        while(r<n)
        {
            if(s.find(nums[r])==s.end())
            {
                sum+=nums[r];
                res=max(sum,res);
                s.insert(nums[r]);
                r++;
                
                
            }
            else
            {
                s.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
            
            
        }
        return res;
    }
};