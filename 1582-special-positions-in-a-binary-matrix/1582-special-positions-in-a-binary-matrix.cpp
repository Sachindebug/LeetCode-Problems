class Solution {
public:
    int numSpecial(vector<vector<int>>& nums) {
        unordered_map<int,int> row,col;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                if(nums[i][j])
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int res = 0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                if(nums[i][j] and row[i]==1 and col[j]==1)
                {
                    res++;
                }
            }
        }
        return res;
    }
};