class Solution {
public:
    bool hasAlternatingBits(int n) {
        ///01010
        
        bool lstbit=true;
        if((n&1)==0) lstbit=false;
        n/=2;
        while(n>0)
        {
            if((n&1) && (!lstbit)) lstbit=true;
            else if((!(n&1)) && lstbit) lstbit=false;
            else return false;
            n/=2;
            
        }
        return true;
        
    }
    
    ///10100 
    //
};