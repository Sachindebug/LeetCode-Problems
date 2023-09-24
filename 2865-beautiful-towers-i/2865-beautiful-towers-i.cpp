class Solution {
public:
    long long calc(vector<int> &arr, int idx)
    {
        long long sum1 = 0,sum2=0;
        int mn1 = arr[idx];
        int mn2 = arr[idx];
        for(int j=idx-1;j>=0;j--)
        {
            if(arr[j]<mn1)
            {
                sum1+=(1ll*arr[j]);
                mn1=arr[j];
            }
            else
            {
                sum1 += (1ll*mn1);
            }
        }
        for(int j=idx+1;j<arr.size();j++)
        {
            if(arr[j]<mn2)
            {
                sum2+=(1ll*arr[j]);
                mn2=arr[j];
            }
            else
            {
                sum2 += (1ll*mn2);
            }
        }
        return (1ll*arr[idx])+sum1+sum2;
    }
    long long maximumSumOfHeights(vector<int>& arr) {
        long long res = 0;
        for(int i=0;i<arr.size();i++)
        {
            res = max(res,calc(arr,i));
        }
        return res;
        
    }
};