class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp=nums;
        int n=nums.size();
        sort(temp.begin(),temp.end());
        int l=-1,r=-1;
        for(int i=0;i<n;i++)
        {
            if(temp[i]!=nums[i])
            {
                l=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(temp[i]!=nums[i])
            {
                r=i;
                break;
            }
        }
        if(l==-1 || r==-1) return 0;
        return r-l+1;
        
    }
};