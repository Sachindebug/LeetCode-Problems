class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1;
        int num2=-1;
        int c1=0;
        int c2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==num1) c1++;
            else if(nums[i]==num2) c2++;
            else if(c1==0)
            {
                num1=nums[i];
                c1++;
            }
            else if(c2==0)
            {
                num2=nums[i];
                c2++;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        vector<int> res;
        c1=0;c2=0;
        for(auto x:nums)
        {
            if(x==num1) c1++;
        }
        if(c1>nums.size()/3) res.push_back(num1);
        for(auto x:nums)
        {
            if(x==num2) c2++;
        }
        if(c2>nums.size()/3 && num1!=num2) res.push_back(num2);
        return res;
        
    }
};