class Solution {
public:
    int pivotInteger(int n) {
        int x=(n*(n+1))/2;
        int s=sqrt(x);
        if(s*s==x)
        {
           return s; 
        }
        return -1;
    }
};