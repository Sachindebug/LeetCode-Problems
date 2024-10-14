class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto x:nums) pq.push(x);
        long long res=0;
        while(k--)
        {
            int x=pq.top();
            res+=x;
            pq.pop();
            pq.push(ceil(double(x)/3.0));
        }
        return res;
    }
};