class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto x:nums)
        {
            pq.push(x);
        }
        while(k>0)
        {
            int x=pq.top();
            pq.pop();
            pq.push(x+1);
            k--;
        }
        long long int mod=1000000007;
        long long int res=1;
        while(!pq.empty())
        {
            int x=pq.top();
            pq.pop();
            res=res*x;
            res=res%mod;
        }
        return res;
        
    }
};