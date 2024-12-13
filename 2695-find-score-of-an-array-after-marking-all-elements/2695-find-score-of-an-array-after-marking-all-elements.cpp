class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int,int>> arr;
        long long int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        int n=nums.size();
        vector<int> vis(n,false);
        for(int i=0;i<n;i++)
        {
            long long int ele=arr[i].first;
            int idx=arr[i].second;
            if(!vis[idx])
            {
                sum+=ele;
                vis[idx]=true;
                if(idx>0) vis[idx-1]=true;
                if(idx<n-1) vis[idx+1]=true;
            }
        }
        return sum;
        
    }
};