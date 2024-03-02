class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int p;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            {
                p=i;
                break;
            }
        }
        int i=p-1;
        int j=p;
        if(j==0)
        {
            for(int k=0;k<nums.size();k++)
            {
                res.push_back(nums[k]*nums[k]);
            }
            return res;
        }
        
        while(i>=0 && j<nums.size())
        {
            int x=(nums[i]*nums[i]);
            int y=(nums[j]*nums[j]);
            if(x<=y)
            {
                res.push_back(x);
                i--;
            }
            else
            {
                res.push_back(y);
                j++;
            }

        }
        while(i>=0)
        {
            int x=nums[i]*nums[i];
            res.push_back(x);
            i--;
        }
        while(j<nums.size())
        {
            int x=nums[j]*nums[j];
            res.push_back(x);
            j++;
        }

        return res;
        
        
    }
};