class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        int i = 0, j = 0;
        unordered_map<long long, long long> mp;
        long long cnt = 0;
        while(j < nums.size()){
            cnt -= mp[nums[j]] * (mp[nums[j]] - 1)/2;
            mp[nums[j]]++;
            cnt += mp[nums[j]] * (mp[nums[j]] - 1)/2;
            if(cnt >= k){
                int t = i;
                while(cnt >= k && i <= j){
                    cnt = cnt - (mp[nums[i]] * (mp[nums[i]] - 1)/2);
                    mp[nums[i]]--;
                    cnt = cnt + (mp[nums[i]] * (mp[nums[i]] - 1)/2);
                    ++i;
                }
                if(i - t == 1 || (nums.size() - j - 1) == 0) ans = ans + (nums.size() - j - 1) + i - t;
                else ans = ans + (nums.size() - j) * (i - t);
                //cout<<nums.size()<<" "<<i<<" "<<j<<" "<<ans<<endl;
            }
            ++j;
        }
        return ans;
    }
};