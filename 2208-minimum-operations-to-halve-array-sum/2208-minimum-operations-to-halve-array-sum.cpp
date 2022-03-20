class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=0;
        priority_queue<double> pq;
        
        for(auto x:nums)
        {
            sum+=x;
            double y=double(x);
            pq.push(y);
        }
        double half=sum/2;
        int res=0;
        while(sum>half)
        {
            double x=pq.top();
            double y=x/2;
            sum-=y;
            pq.pop();
            pq.push(y);
            res++;
        }
        return res;
    }
};