class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int>> s;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(abs(nums[i]-nums[j])==k)
                {
                    int x=min(nums[i],nums[j]);
                    int y=max(nums[i],nums[j]);
                    pair<int,int> p={x,y};
                    s.insert(p);

                }
            }
        }
        return s.size();
    }
};