class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1=1e9+1;
        int n2=1e9+1;
        int c1=0,c2=0;
        for(auto x:nums)
        {
            if(x==n1) c1++;
            else if(x==n2) c2++;
            else if(c1==0)
            {
                n1=x;
                c1=1;
            }
            else if(c2==0)
            {
                n2=x;
                c2=1;
            }
            else {
                c1--;
                c2--;
            }
        }
        c1=0;c2=0;
        for(auto x:nums) if(x==n1) c1++;
        for(auto x:nums) if(x==n2) c2++;
        int n=nums.size();
        vector<int> res;
        if(c1>(n/3)) res.push_back(n1);
        if(c2>(n/3)) res.push_back(n2);
        return res;

    }
};