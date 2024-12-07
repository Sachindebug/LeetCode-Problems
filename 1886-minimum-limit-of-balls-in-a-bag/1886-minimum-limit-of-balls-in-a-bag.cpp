class Solution {
private:
    bool isPossible(vector<int>& nums, int maxOperations,int k){
        int count = 0;
        for(auto x: nums){
            count+=(x/k);
            if(x%k==0) count--;
        }
        return count<=maxOperations;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(nums.begin(),nums.end());
        int ans = -1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(isPossible(nums,maxOperations,m)){
                ans = m;
                r = m - 1;
            }
            else l = m+1;
        }
        return ans;
    }
};