class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<long long,long long>>vp;
         long long weight = 0;
        for(int i=0;i<nums.size();i++){
            vp.push_back({nums[i],cost[i]});
            weight += cost[i];
        }
        long long index = (weight)/2;
        sort(vp.begin(),vp.end());
        long long v1=-1,v2=-1;
        long long add=0;
        for(int i=0;i<nums.size();i++){
            add += vp[i].second;
            if(add>=index && v1==-1)v1=vp[i].first;
            if(add>=(index+1) && v2==-1)v2=vp[i].first;
        }
        cout<<index;
        long long s1=0,s2=0;
        for(int i=0;i<nums.size();i++){
            s1 += 1LL*abs(v1-vp[i].first)*vp[i].second;
            s2 += 1LL*abs(v2-vp[i].first)*vp[i].second;
        }
        return min(s1,s2);
    }
};