class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int>> s;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++)
        {
            int x=k+nums[i];
            int y=nums[i]-k;
            if(binary_search(nums.begin()+i+1,nums.end(),x))
            {
                int a=min(nums[i],x);
                int b=max(nums[i],x);
                pair<int,int> p={a,b};
                s.insert(p);
            }
            if(binary_search(nums.begin()+i+1,nums.end(),y))
            {
                int a=min(nums[i],y);
                int b=max(nums[i],y);
                pair<int,int> p={a,b};
                s.insert(p);
            }
            
            
        }
        return s.size();
    }
};