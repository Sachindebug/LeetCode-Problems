class Solution {
public:
    int numberOfSteps (int n) {
        int count=0,count1=0;
        if(n==0)
        {
            return 0;
        }
        while(n>0)
        {
            if(n%2!=0)
            {
                n-=1;
                count1++;
            }
            n/=2;
            count++;
        }
        return count+count1-1;
    }
};