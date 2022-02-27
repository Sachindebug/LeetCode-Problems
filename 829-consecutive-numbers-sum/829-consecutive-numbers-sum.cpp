class Solution {
public:
    int consecutiveNumbersSum(int n) {
       int count=0;
       long long int x=1;
       while(true)
       {
          long long int p=x*(x-1)/2;
          if(n<=p) break;
          long long int a=n-p;
          if(a%x==0){
             count++;
             
          } 
          x++;
            
       }
       return count;
    }
};