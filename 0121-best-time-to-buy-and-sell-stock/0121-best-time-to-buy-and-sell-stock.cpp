class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int mx = 0;
        for(int i = prices.size()-1; i>=0; i--){
            mx = max(prices[i],mx);
            res = max(mx-prices[i],res);
        }
        return res;
    }
};