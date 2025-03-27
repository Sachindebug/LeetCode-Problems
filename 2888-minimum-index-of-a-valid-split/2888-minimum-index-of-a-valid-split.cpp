class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int> ump;
        for(int i:nums) ump[i]++;
        int res=-1;
        int freq=0;
        for(auto x:ump){
            if((x.second)>freq){
                freq=x.second;
                res=x.first;
            }
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            int curr = i+1;
            int rem = nums.size()-i-1;
            if(nums[i]==res) count++;
            int remcount = freq-count;
            if(count*2>curr && remcount*2>rem) return i;
            
        }
        return -1;
    }
};