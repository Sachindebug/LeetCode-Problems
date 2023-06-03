//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        // code here
        vector<long long int> res;
        long long int x=0,k,x1=0,x2=0;
        for(int i=0;i<n;i++) x^=arr[i];
        for(int i=0;i<64;i++)
        {
            if(x&(1<<i))
            {
                k=i;
                break;
            }
        }
        ;
        for(int i=0;i<n;i++)
        {
            if(arr[i]&(1<<k))
            {
                x1^=arr[i];
            }
            else
            {
                x2^=arr[i];
            }
        }
        long long int mx=max(x1,x2);
        long long int mn=min(x1,x2);
        return {mx,mn};
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends