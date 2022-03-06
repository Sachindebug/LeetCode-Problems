class Solution {
public:
    int countOrders(int n) {
        long long mod=1000000007;
        int arr[n+1];
        arr[1]=1;
        for(int i=2;i<=n;i++)
        {
            arr[i]=((arr[i-1])%mod*((i%mod*(2*i-1)%mod)%mod)%mod)%mod;
        }
        return arr[n];
    }
};