// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    long long int prev = 1;
        long long int curr = 2,temp;
        for(int i=2;i<=N;i++){
            temp = (prev % 1000000007 + curr % 1000000007) % 1000000007;
            prev = curr;
            curr = temp;
        }
        return (curr % 1000000007 * curr % 1000000007) % 1000000007;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends