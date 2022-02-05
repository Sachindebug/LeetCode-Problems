class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int time) {
        int res=INT_MAX;
        int a1,b1,c1,d1;
        int a2,b2,c2,d2;
        int x,y;
        x=time/60;
        b1=x%10;
        a1=x/10;
        y=time%60;
        d1=y%10;
        c1=y/10;
        if(x>99)
        {
            x--;
            y+=60;
            b2=x%10;
            a2=x/10;
            d2=y%10;
            c2=y/10;
            int res2=cost(a2,b2,c2,d2,moveCost,pushCost,startAt);
            res=min(res,res2);
            return res;
            
        }
        
        int res1;
        res1=cost(a1,b1,c1,d1,moveCost,pushCost,startAt);
        res=min(res,res1);
        if(y<40 && x>0) 
        {
            x--;
            y+=60;
            b2=x%10;
            a2=x/10;
            d2=y%10;
            c2=y/10;
            int res2=cost(a2,b2,c2,d2,moveCost,pushCost,startAt);
            res=min(res,res2);
            
        }

        
        return res;
    }
    int cost(int a,int b,int c,int d,int mvc,int psc,int start)
    {
        int res=0;
        if(a==0)
        {
           res+=0; 
        }
        else
        {
            if(a==start)
            {
                res+=psc;
            }
            else
            {
                res+=(mvc+psc);
            }
        }
        if(a==0 && b==0)
        {
            res+=0;
        }
        else
        {
            if(a==0)
            {
                if(b==start)
                {
                res+=psc;
                }
            else
            {
                res+=(mvc+psc);
            }
                
            }
            else
            {
                if(a==b)
            {
                res+=psc;
            }
            else
            {
                res+=(mvc+psc);
            }
                
            }
        }
        if(a==0 && b==0 && c==0)
        {
            res+=0;
        }
        else if(a==0 && b==0 && c!=0)
        {
            if(c==start)
            {
                res+=psc;
            }
            else
            {
                res+=(psc+mvc);
            }
        }
        else
        {
            if(b==c)
            {
                res+=psc;
            }
            else
            {
                res+=(psc+mvc);
            }
        }
        if(a==0 && b==0 && c==0)
        {
            if(d==start)
            {
                res+=psc;
            }
            else
            {
                res+=(mvc+psc);
            }
        }
        else
        {
            if(c==d)
            {
                res+=psc;
            }
            else
            {
                res+=(mvc+psc);
            }
        }
        return res;
    }
};