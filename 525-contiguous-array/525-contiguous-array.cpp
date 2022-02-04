class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                nums[i]=-1;
            }
        }
        unordered_map<int,vector<int>> ump;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            ump[sum].push_back(i);
        }
        int res=INT_MIN;
        for(auto x:ump)
        {
            int s=x.first;
            if(s==0) res=max(res,x.second[x.second.size()-1]+1);
            else
            {
                res=max(res,x.second[x.second.size()-1]-x.second[0]);
            }
        }
        
        return res;
    }
};