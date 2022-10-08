class Solution {
public:
    bool winnerOfGame(string colors) {
        int a=0;
        int b=0;
        int res=1;
        for(int i=1;i<colors.size();i++)
        {
            if(colors[i]==colors[i-1])
            {
                res++;
            }
            else
            {
                if(colors[i-1]=='A')
                {
                    a+=max(0,res-2);
                }
                else
                {
                    b+=max(0,res-2);
                }
                res=1;
            }
        }
        if(colors[colors.size()-1]=='A')
        {
            a+=max(0,res-2);
        }
        else
        {
            b+=max(0,res-2);
        }
        
        return a>b;
    }
};