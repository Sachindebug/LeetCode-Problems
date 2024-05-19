class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) {
        int count = 1;
        unordered_map<int,int> ump;
        ump[0] = count;
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i]%2==nums[i-1]%2) count++;
            ump[i] = count;
        }
        vector<bool> res;
        for(auto x:q){
            int u = x[0],v = x[1];
            res.push_back(ump[u]==ump[v]);
        }
        return res;
    }
};