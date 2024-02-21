class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        if(l==r) return l;
        if(l==0 || r==0) return 0;
        if(int(log2(l))!=int(log2(r))) return 0;
        long long int res=l;
        for(int i=l;i<r;i++)
        {
            res&=i;
        }
        res&=r;
        return res;
    }
};