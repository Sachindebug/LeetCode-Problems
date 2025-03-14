class Solution {
public:
    bool isPossible(vector<int> &nums, long long k, long long m){
        long long count = 0;
        for(auto x: nums){
            count+=(1ll*x/m);
        }
        return count>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long l = 1;
        long long r = 0;
        for(auto x: candies) r = max(1ll*x,r);
        long long res = 0;
        while(l<=r){
            long long m = l+(r-l)/2;
            if(isPossible(candies,k,m)){
                res = m;
                l = m+1;
            }
            else r = m-1;
        }
        return res;
    }
};