// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int FindNthTerm(long long int n) {
        // Code here
        long long int f[2][2]={{1,1},{1,0}};
       
       power(f,n);
       
       return f[0][0];
       
        
    }
    
    void multiplication(long long int a[2][2],long long int b[2][2])
    {
        long long int p=((a[0][0]*b[0][0])%1000000007+(a[0][1]*b[1][0])%1000000007)%1000000007;
        long long int q=((a[0][0]*b[0][1])%1000000007+(a[0][1]*b[1][1])%1000000007)%1000000007;
       long long  int r=((a[1][0]*b[0][0])%1000000007+(a[1][1]*b[1][0])%1000000007)%1000000007;
       long long  int s=((a[1][0]*b[0][1])%1000000007+(a[1][1]*b[1][1])%1000000007)%1000000007;
        
        a[0][0]=p;
        a[0][1]=q;
        a[1][0]=r;
        a[1][1]=s;
    }
    
    void power(long long int a[2][2],long long int n)
    {
        if(n==0||n==1) return;
        long long int m[2][2]={{1,1},{1,0}};
        power(a,n/2);
        multiplication(a,a);
        if(n%2!=0)
        multiplication(a,m);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends