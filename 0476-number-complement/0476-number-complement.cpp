class Solution {
public:
    int findComplement(int n) {
        if(n==0) return 1;
        long long int res=setBitNumber(n);
        res+=res;
        res-=1;
        cout<<res<<endl;
        return res^n;
        
    }

    long long int setBitNumber(long long int n)
    {
        if (n == 0)
            return 0;
        long long int msb = 0;
        n = n / 2;
        while (n != 0) {
            n = n / 2;
            msb++;
        }
        return (1 << msb);
    }
};