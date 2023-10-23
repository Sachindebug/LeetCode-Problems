class Solution {
public:
    bool isPowerOfFour(int n) {
        //00100
        //0001
        //0010000
        //001000000
        
        //even
        int count=0;
        int p=n;
        while(p>0)
        {
            p=p&(p-1);
            count++;
        }
        if(count==1)
        {
            int idx=0;
            while(n)
            {
                if(n&1) break;
                n=n>>1;
                idx++;
            }
            if(idx%2==0) return true;
            else return false;
            
        }
        // 1
        return false;
        
        
       
    }
};