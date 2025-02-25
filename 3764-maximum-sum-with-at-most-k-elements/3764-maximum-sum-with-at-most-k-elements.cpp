class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int> pq;
        for(int i = 0;i <limits.size();i++){
            vector<int> x = grid[i];
            int lim = limits[i];
            int n = x.size();
            sort(x.begin(),x.end(),greater<>());
            lim = min(lim, n);
            for(int j = 0;j<lim;j++){
                pq.push(x[j]);
            }
        }
        long long sum = 0;
        while(!pq.empty() && k--){
            sum+=1ll*(pq.top());
            pq.pop();
        }
        return sum;
    }
};