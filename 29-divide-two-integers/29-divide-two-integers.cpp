class Solution {
public:
    int divide(int dd, int ds) {
        
        long long int dividend=dd;
        long long int divisor=ds;
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        bool diend=false;
        bool divi=false;
        if(dividend<0) {diend=true; dividend*=-1;}
        if(divisor<0) {divi=true; divisor*=-1;}
        long long int x=dividend/divisor;
        if(diend && divi) return x;
        if(diend || divi) return -x;
        return x;
    }
};