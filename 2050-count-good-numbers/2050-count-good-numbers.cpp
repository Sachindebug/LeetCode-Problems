class Solution {
public:
    long long int power(long long int x, long long int y, long long int p=1e9+7)
    {
        long long int res = 1;
        while (y > 0) {
            if (y % 2 == 1)
                res = (res * x)%p;
            y = y >> 1;
            x = (x * x)%p;
        }
        return res % p;
    }
    int countGoodNumbers(long long n) {
        long long int x=n/2;
        long long int mod=1e9+7;
        long long int y=n/2;
        if(n%2) x++;
        return ((power(5,x)%mod)*(power(4,y)%mod))%mod;
    }
};