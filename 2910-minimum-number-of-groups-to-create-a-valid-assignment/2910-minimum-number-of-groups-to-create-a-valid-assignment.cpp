class Solution {
public:
    bool solve(vector<int> v,int mid){
        int s;
        for(int i=0;i<v.size();++i){
            s = v[i]/mid;
            if(v[i]%mid > s)return false;
        }
        return true;
    }
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();++i){
            mp[nums[i]]++;
        }
        int mn=nums.size();
        vector<int> v;
        for(auto &e:mp){
            mn = min(mn,e.second);
            v.push_back(e.second);
        }
        while(!solve(v,mn)){
            mn--;
        }
        int mid =mn;
        // cout<<mid;
        int ans=0;
        for(int i=0;i<v.size();++i){
            while((v[i]%(mid+1))!=0){
                v[i]-=mid;
                ans++;
            }
            if((v[i]%(mid+1))==0){
                ans += v[i]/(mid+1);
            }
        }
        return ans;
    }
};