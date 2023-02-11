class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int res=0;
        int mx=0;
        for(int i=arr.size()-1;i>=0;i--)
        {
            mx=max(mx,arr[i]);
            res=max(res,mx-arr[i]);
        }
        return res;
    }
};