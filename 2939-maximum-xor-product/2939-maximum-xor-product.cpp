class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
       long long m=1e9+7;
        
           for(int i=n-1;i>=0;i--)
           {
               if(a>b)
                   swap(a,b);
               int p1=(a&(1LL<<i))>0;
               int p2=(b&(1LL<<i))>0;
               
               if(p1==0)
               {
                   a^=(1LL<<i);
                   b^=(1LL<<i);
               }
           }
        
         long long ans=(( a%m)*(b%m))%m;
          return ans;
        
    }
};