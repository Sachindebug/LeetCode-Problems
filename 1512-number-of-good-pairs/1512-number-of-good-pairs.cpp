class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       int sum=0;
       unordered_map<int,int> ump;
        
        for(int i=0;i<nums.size();i++)
        {
            ump[nums[i]]++;
        }
        for(auto x:ump)
        {
            sum+=(x.second)*((x.second)-1)/2;
        }
        return sum;
       
    }
};