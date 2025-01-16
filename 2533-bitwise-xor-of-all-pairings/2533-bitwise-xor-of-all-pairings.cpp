class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int x1=0,x2=0;
        for(auto x:nums1) x1^=x;
        for(auto x:nums2) x2^=x;
        if(n%2==0 && m%2==0)
        {
            return 0;
        }
        else if(n%2==1 && m%2==0)
        {
            return x2;
        }
        else if(n%2==0 && m%2==1)
        {
            return x1;
        }
        return x1^x2;
    }
};