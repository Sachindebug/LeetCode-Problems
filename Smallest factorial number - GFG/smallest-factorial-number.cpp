// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    int trailing(int n)
     {   
         int ans=0;
         for(int i=5;i<=n;i*=5)
         {
             ans+=n/(i);
         }
         return ans;
     }
    public:
        int solve(int l,int h,int zeros)
      {
         while(l<h)
         {
          int mid=l+(h-l)/2;
          if(trailing(mid)>=zeros)
          {
                 h=mid;
          }
          else
          {
            l=mid+1;
          }
        }
        return l;
          
      }
        int findNum(int n)
        {
        //complete the function here
        return solve(0,5*n,n);
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends