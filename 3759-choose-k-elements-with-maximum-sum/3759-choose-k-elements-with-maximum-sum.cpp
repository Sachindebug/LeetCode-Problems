class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, pair<int, int>>> arr;
        vector<long long> res(nums1.size(), 0);
        for (int i = 0; i < nums1.size(); i++) {
            arr.push_back({nums1[i], {nums2[i], i}});
        }

        sort(arr.begin(), arr.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        int prevVal = 0;
        long long prevSum = 0;
        for (auto item : arr) {
            if (item.first == prevVal) res[item.second.second] = prevSum;
            else {
                res[item.second.second] = sum;
                prevSum = sum;
            }
            pq.push(item.second.first);
            sum += item.second.first;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            prevVal = item.first;
        }    

        return res;
    }
};