class Solution {
public:
    bool ispossible(vector<int> &nums, int m,int k)
    {
        int sum=0;
        int count=0;
        for(auto x:nums)
        {
            if(x>m) return false;
            if(sum+x<=m)
            {
                sum+=x;
            }
            else
            {
                sum=x;
                count++;
            }
        }
        count++;
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=0;
        int r=1e9+1;
        int res=-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(ispossible(nums,m,k))
            {
                res=m;
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return res;
    }
};