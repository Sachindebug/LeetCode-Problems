class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        
        for (int num: nums1) {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }
        
        for (int num: nums2) {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }
        
        if (firstMax < 0 && secondMin > 0) {
            return firstMax * secondMin;
        }
        
        if (firstMin > 0 && secondMax < 0) {
            return firstMin * secondMax;
        } 
        vector<vector<int>> dp(nums1.size(), vector(nums2.size(), 0));
        return recurse(nums1,nums2,0,0,dp);
    }
    long long int recurse(vector<int>& nums1, vector<int>& nums2, int i,int j,vector<vector<int>> &dp)
    {
        if(i==nums1.size() || j==nums2.size()) return 0;
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        long long res = recurse(nums1,nums2,i+1,j,dp);
        res = max(res,recurse(nums1,nums2,i,j+1,dp));
        res = max(res,1ll*nums1[i]*nums2[j]+recurse(nums1,nums2,i+1,j+1,dp));
        return dp[i][j]=res;
    }
};