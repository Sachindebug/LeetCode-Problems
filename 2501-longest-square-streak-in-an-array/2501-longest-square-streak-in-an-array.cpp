class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        int len=0;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            long long int x=nums[i];
            while(s.find(x)!=s.end())
            {
                
                s.erase(s.find(x));
                x*=x;
                len++;
            }
            res=max(res,len);
            len=0;
        }
        if(res<=1) return -1;
        return res;
        
    }
};