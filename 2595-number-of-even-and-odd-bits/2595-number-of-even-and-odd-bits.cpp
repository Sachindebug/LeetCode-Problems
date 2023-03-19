class Solution {
public:
    vector<int> evenOddBit(int n) {
        int odd=0,even=0;
        for(int i=0;i<32;i++)
        {
            if(n&(1<<i)) 
            {
                if(i%2) odd++;
                else even++;
            }
        }
        return {even,odd};
      
    }
};