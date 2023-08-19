class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
         unordered_map<int,int> mp;
        
        for(auto it:nums) mp[it]++;
        int count=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int> s;
            for(int j=i;j<nums.size();j++){
                s.insert(nums[j]);
                if(s.size()==mp.size()) count++;
            }
        }
        return count;
    }
};