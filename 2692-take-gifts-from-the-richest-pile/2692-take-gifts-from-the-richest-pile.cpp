class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq;
        for(auto x:gifts) pq.push(x);
        while(k--)
        {
            long long x=pq.top();
            
            pq.pop();
            pq.push(sqrt(x));
        }
        
        long long sum=0;
        while(pq.size())
        {
           
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};