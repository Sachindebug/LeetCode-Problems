class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return {};
        vector<int> res;
        int prev=0;
        int curr;
    
        for(int i=0;i<n;i++)
        {
            int count=0;
            while(count<=n && nums[i]!=i+1 && nums[nums[i]-1]!=nums[i])
            {
                swap(nums[nums[i]-1],nums[i]);
                count++;
            }
            
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                res.push_back(nums[i]);
            }
        }
        return res;
        
    }
};