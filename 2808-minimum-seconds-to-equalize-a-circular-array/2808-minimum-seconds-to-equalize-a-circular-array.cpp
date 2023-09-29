class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int,vector<int>> mp; 
        for(int i=0;i<nums.size();i++)
        { 
            mp[nums[i]].push_back(i);  // storing in map
        } 
        int mn=INT_MAX; 
        for(auto it:mp)
        { 
            vector<int> v=it.second; 
            int cur=(v[0]-0)+(nums.size()-1-v[v.size()-1]); 
            for(int i=0;i<v.size()-1;i++){ 
                cur=max(cur,v[i+1]-v[i]-1);  // checking condition
            } 
            cur=ceil((double)cur/2); 
            mn=min(mn,cur); 
        } 
        return mn; 
    }
};