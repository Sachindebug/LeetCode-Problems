class Solution {
public:
    int minOperations(int n) {
        double x= log2(n);
        if(floor(x)==ceil(x)) return 1;
        int p= 1<<int(x);
        int q= 1<<int(ceil(x));
        return 1+min(minOperations(n-p),minOperations(q-n));

    }
};