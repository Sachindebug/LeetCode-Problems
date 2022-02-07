class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int req=target;
        int count=0;
        while(req!=1 && req>0)
        {
            if(maxDoubles>0)
            {
                if(req%2==0)
                {
                   req/=2;
                   maxDoubles--;
                   count++;
                }
                else
                {
                    req--;
                    count++;
                }
                
            }
            else
            {
                count+=(req-1);
                req=0;
                    
            }
            
       }
       return count;
    }
};