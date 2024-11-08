class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int m) {
        vector<int> res;
        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            x=x^nums[i];
            int temp=0;
            for(int j=0;j<m;j++)
            {
                if(!(x&(1<<j)))
                {
                    temp = temp | (1<<j);
                }
            }
            res.push_back(temp);
        
                   
        }
        reverse(res.begin(),res.end());
        return res;
            
    }
};