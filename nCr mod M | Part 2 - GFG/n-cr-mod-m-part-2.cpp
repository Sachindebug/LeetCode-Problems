// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
int countFact(int n, int p)
{
    int k=0;
    while (n>0)
    {
        k+=n/p;
        n/=p;
    }
    return k;
}
long long pow(int a, int b, int MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}
public:
int nCrModM(int n, int r, int MOD) {
    long long res = 1;
    vector<bool> isPrime(n+1,1);
    for (int i=2; i<=n; i++)
        if (isPrime[i])
        {
            for (int j=2*i; j<=n; j+=i)
                isPrime[j]=0;
            int k = countFact(n,i) - countFact(r,i) - countFact(n-r,i);  
            res = (res * pow(i, k, MOD)) % MOD;
        }
    return res;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, r, m;
		cin >> n >> r >> m;
		Solution obj;
		int ans = obj.nCrModM(n, r, m);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends