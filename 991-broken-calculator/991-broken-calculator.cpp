class Solution {
public:
    int brokenCalc(int s, int t) {
        int res=0;
        while(s!=t)
        {
            if(t%2==0 && t>s)
            {
                t/=2;
            }
            else
            {
                t+=1;
            }
            res++;
        }
        res+=abs(s-t);
        return res;
        
    }
};