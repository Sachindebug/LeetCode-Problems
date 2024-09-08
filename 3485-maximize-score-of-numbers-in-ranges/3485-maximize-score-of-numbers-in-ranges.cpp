class Solution {
public:
    bool isPossible(vector<int> &nums, int d, long long mid){
        int n = nums.size();
        long long prev = nums[0];
        for(int i = 1;i<n;i++){
            long long int next=max(prev+mid, static_cast<long long>(nums[i]));
            if (next > nums[i] + d) { 
                return false;
            }
            prev = next;
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());
        int n = start.size();
        long long l = 0;
        long long r = start[n-1]+d;
        long long res = -1;
        while(l<=r){
            long long m = l+(r-l)/2;
            if(isPossible(start,d,m)){
                res = m;
                l = m+1;
            }
            else r = m-1;
        }
        return res;
    }
};