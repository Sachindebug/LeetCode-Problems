// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        //code here
        int m=1e9+7,a=0,b=0,c=0;
        for(int i=0;i<s.size();i++){
           if(s[i]=='a')a=(2*a%m+1)%m;
           else if(s[i]=='b')b=(2*b%m+a%m)%m;
           else c=(2*c%m+b%m)%m;
        }
        return c;
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends