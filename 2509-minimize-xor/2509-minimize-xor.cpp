class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int arr1[32]={0};
        int arr2[32]={0};
        int count1=0;
        int count2=0;
        for(int i=0;i<32;i++)
        {
            if(num1 & (1<<i)) 
            {
                arr1[i]=1;
                count1++;
            }
            if(num2 & (1<<i)) 
            {
                arr2[i]=1;
                count2++;
            }
        }
        int res=0;
        for(int i=31;i>=0;i--)
        {
            if(arr1[i] && count2>0)
            {
                res+=(1<<i);
                count2--;
            }
        }
        if(count2>0)
        {
           for(int i=0;i<32;i++)
           {
              if(!arr1[i] && count2>0)
              {
                    res+=(1<<i);
                    count2--;
              }
           }
        }
        return res;
        
    }
};