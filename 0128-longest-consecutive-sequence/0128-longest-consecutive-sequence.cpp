class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        if(n<=1) return n;
        for(auto x:nums) s.insert(x);
        int res=0;
        for(auto x:s)
        {
            int count=0;
            if(s.find(x-1)==s.end())
            {
                while(s.find(x)!=s.end())
                {
                    count++;
                    x=x+1;
                }
            }
            res=max(count,res);
            
        }
        return res;
        
    }
};