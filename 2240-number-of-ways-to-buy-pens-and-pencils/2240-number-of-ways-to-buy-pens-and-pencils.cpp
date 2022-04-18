class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long res=0;
        while(total>=0)
        {
            int x=total/cost2;
            res+=(x+1);
            total-=cost1;
        }
        return res;
    }
};