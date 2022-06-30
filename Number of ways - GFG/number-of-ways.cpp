// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    vector<long long int> dp;
public:
    long long int arrangeTiles(int n){
        dp.resize(n+1,-1);
        // code here
        return recurse(n);
        
    }
    long long int recurse(int n)
    {
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        
        return dp[n]=recurse(n-1)+recurse(n-4);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends