class Solution {
public:
    int minFlips(int a, int b, int c) {
        int r=0;
        
        for(int i=0;i<32;i++)
        {
            bool x=false,y=false,z=false;
            if(a & (1 << i))
            {
                x=true;
            }
            if(b & (1 << i))
            {
                y=true;
            }
            if(c & (1 << i))
            {
                z=true;
            }
            if(z==false)
        {
            if(x==true && y==true)
            {
                r+=2;
            }
            else if(x==true || y==true)
            {
                r++;
            }
        }
        else
        {
            if(x==false && y==false)
            {
                r++;
            }
        }
        }
        
        return r;
        
    }
};