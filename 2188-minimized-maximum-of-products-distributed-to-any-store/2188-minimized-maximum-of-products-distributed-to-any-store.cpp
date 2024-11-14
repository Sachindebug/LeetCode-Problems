class Solution {
public:
    bool isPossible(vector<int>& nums, int m, int p){
        int count = 0;
        for(auto x: nums){
            if(x%m==0) count+=(x/m);
            else count+=(1+(x/m));
        }
        return count<=p;
    }
    int minimizedMaximum(int n, vector<int>& nums) {
        int l = 1;
        int r = *max_element(nums.begin(),nums.end());
        int res = -1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(isPossible(nums,m,n)){
                res = m;
                r = m-1;
            }
            else l = m+1;
        }
        return res;
    }
};