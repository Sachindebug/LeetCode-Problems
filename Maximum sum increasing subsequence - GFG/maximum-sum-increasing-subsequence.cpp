//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	    return recurse(arr,n,0,-1,dp);
	}  
	int recurse(int arr[],int n,int idx,int prev,vector<vector<int>> &dp)
	{
	    if(idx==n) return 0;
	    if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
	    if(prev==-1 || arr[prev]<arr[idx])
	    {
	        return dp[idx][prev+1]=max(arr[idx]+recurse(arr,n,idx+1,idx,dp),recurse(arr,n,idx+1,prev,dp));
	    }
	    return dp[idx][prev+1]=recurse(arr,n,idx+1,prev,dp);
 	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends