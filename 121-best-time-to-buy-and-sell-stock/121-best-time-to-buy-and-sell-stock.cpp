class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int minele=INT_MAX;
        int res=INT_MIN;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            minele=min(minele,arr[i]);
            res=max(res,arr[i]-minele);
        }
        return res;
    }
};