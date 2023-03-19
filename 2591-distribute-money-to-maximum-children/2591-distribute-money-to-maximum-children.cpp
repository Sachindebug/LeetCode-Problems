class Solution {
public:
    int distMoney(int m, int c){
        if(m<c) return -1;
        for(int i=c;i>=1;i--)
        {
            int x = 8*i;
            if(x>m) continue;
            else
            {
                int rem=m-x;
                if(rem>0 && i==c) continue;
                else if(rem<(c-i)) continue;
                else
                {
                    if(rem==4 && i==c-1) continue;
                    else return i;
                }
            }
        }
        return 0;
    }
};