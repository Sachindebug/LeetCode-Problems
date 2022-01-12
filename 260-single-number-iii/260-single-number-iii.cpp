class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        for(auto x:nums)
        {
            res=res^=x;
        }
        int p=0;
        for(p=0;p<32;p++)
        {
            if(res & (1<<p)) break;
        }
        int res1=0;
        int res2=0;
        for(auto x:nums)
        {
            if(x & (1<<p)) res1=res1^x;
            else res2=res2^x;
        }
        return {res1,res2};
        
        
    }
};