class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        int maxsum = nums[n - 1];
        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(nums[n - 1], n - 1));
        for(int i = n - 2; i >= 0; i--){
           while(pq.size() != 0 && (pq.top().second - i) > k) pq.pop();
           maxsum = nums[i] + pq.top().first;
           pq.push(make_pair(maxsum, i));
        }
        return maxsum;
    }
   
};