class Solution {
public:
    double myPow(double x, int n) {
        long long int nn=n;
        if(n<0) nn*=-1;
        double res=1;
        while(nn>0)
        {
            if(nn%2==0)
            {
                x=x*x;
                nn=nn/2;
            }
            else
            {
                res=res*x;
                nn-=1;
            }
        }
        if(n<0) return double(1)/double(res);
        return res;
    }
};