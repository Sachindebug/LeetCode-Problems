class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            int k=i+2;
            for(int j=i+1;j<n && nums[i]!=0;j++)
            {
                while(k<n && nums[i]+nums[j]>nums[k]) k++;
                res+=k-j-1;

            }
        }
        return res>0?res:0;
            
    }
};