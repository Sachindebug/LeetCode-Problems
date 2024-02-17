class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> ump;
        for(auto x:arr) ump[x]++;
        priority_queue<int> pq;
        for(auto x:ump) pq.push(-x.second);
        while(k>0)
        {
            auto x = -pq.top();
            if(x>k) break;
            k-=x;
            pq.pop();
        }
        return pq.size();
    }
};