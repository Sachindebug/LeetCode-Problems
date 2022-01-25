class Solution {
public:
    int countGoodNumbers(long long n) {
        long long a,b;
        a=n/2;
        b=n/2;
        if(n%2) b++;
        long long res=binpow(4,a);
        res=res%1000000007;
        res=((res%1000000007)*(binpow(5,b)%1000000007))%1000000007;
        return res;
        
    }
    long long int binpow(long long a,long long b)
    {
        long long m=1000000007;
        a %= m;
        long long res = 1;
        while (b > 0) {
        if (b & 1)
            res = res * a % m;
             a = a * a % m;
             b >>= 1;
        }
        return res;
    }
};