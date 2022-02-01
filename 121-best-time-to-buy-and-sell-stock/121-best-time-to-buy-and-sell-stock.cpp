class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> res(prices.size(),0);
        int n=prices.size();
        int mx=-1;
        for(int i=n-1;i>=0;i--)
        {
            res[i]=mx;
            if(prices[i]>mx)
            {
                mx=prices[i];
            }
        }
        mx=res[0]-prices[0];
        for(int i=1;i<n;i++)
        {
            if((res[i]-prices[i])>mx)
            {
                mx=(res[i]-prices[i]);
            }
        }
        return mx>0?mx:0;
        
        
    }
};