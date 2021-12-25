class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ump;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            ump[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            int x=target-nums[i];
            if(ump.find(x)!=ump.end() && i!=ump[x])
            {
                res.push_back(i);
                res.push_back(ump[x]);
                break;
            }
            
        }
        return res;
    }
};