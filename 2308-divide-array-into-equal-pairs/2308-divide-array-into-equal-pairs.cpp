class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        map<int,int> ump;
        for(auto x:nums){
            ump[x]++;
        }
        for(auto x:ump){
            if(x.second%2) return false;
        }
        return true;
    }
};