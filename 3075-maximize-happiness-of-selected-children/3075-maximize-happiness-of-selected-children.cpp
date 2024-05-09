class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        int count = 0;
        priority_queue<int> pq(nums.begin(),nums.end());
        long long sum = 0;
        while(k--)
        {
            int x = pq.top();
            pq.pop();
            sum+=1ll*max((x-count),0);
            count++;
        }
        return sum;
    }
};