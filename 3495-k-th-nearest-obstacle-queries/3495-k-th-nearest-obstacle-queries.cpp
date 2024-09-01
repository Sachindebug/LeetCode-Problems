class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& q, int k) {
        vector<int> res;
        priority_queue<int> pq;
        for(auto x:q){
            int sum = abs(x[0])+abs(x[1]);
            pq.push(sum);
            if(pq.size()<k) res.push_back(-1);
            else{
                if(pq.size()>k) pq.pop();
                res.push_back(pq.top());
            }
        }
        return res;
    }
};