class Solution {
public:
    bool isPowerOfTwo(int n) {
       int cnt=0;
       while(n>0)
       {
           cnt++;
           n= n & (n-1);
       }
       if(cnt==1)
       {
           return true;
       }
       return false; 
           
       
    }
};