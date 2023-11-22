class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>> ump;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                ump[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> res;
        for(auto x:ump)
        {
            vector<int> temp = x.second;
            reverse(temp.begin(),temp.end());
            for(auto i:temp) res.push_back(i);
        }
        return res;
    }
};