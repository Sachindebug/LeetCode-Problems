class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int>mp;
        int count=0;
        int rem=0;
        for(auto i : nums)
            mp[i]++;
        for(auto i : mp){
            count+=i.second/2;
            rem+=i.second%2;
        }
        nums.resize(0);
        

        nums.push_back(count);
        nums.push_back(rem);
        return nums;
    }
};