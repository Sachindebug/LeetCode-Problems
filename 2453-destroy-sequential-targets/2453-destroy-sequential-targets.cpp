class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> cnt;
        for (int n : nums)
        ++cnt[n % space];
        return *max_element(begin(nums), end(nums), [&](int a, int b){
        int cnt1 = cnt[a % space], cnt2 = cnt[b % space];
        return cnt1 == cnt2 ? a > b : cnt1 < cnt2;
    });
    }
};