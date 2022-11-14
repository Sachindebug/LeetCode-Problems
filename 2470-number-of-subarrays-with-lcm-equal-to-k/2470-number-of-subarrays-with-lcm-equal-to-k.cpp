class Solution {
public:
    int lcm(int a,int b)
    {
        int g=__gcd(a,b);
        return (a*b)/g;
    }
    int subarrayLCM(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int l=1;
            for(int j=i;j<n;j++)
            {
                l=lcm(l,nums[j]);
                if(l==k) count++;
                else if(l>k) break;
            }
            
        }
        return count;
    }
};