class Solution {
public:
    long long int power(long long int x, long long int y, long long int p)
    {
        long long int res = 1;

        while (y > 0) {

            if (y % 2 == 1)
                res = (res%p * x%p)%p;
                res=res%p;
            y = y >> 1;
            x = (x%p * x%p)%p;
        }
        return res % p;
    }
    int monkeyMove(int n) {
        long long int p=n;
        long long int mod=1e9+7;
        long long int res= power(2,p,1e9+7);
        res-=2;
        res+=(mod);
        res=res%(mod);
        return res;
    }
};