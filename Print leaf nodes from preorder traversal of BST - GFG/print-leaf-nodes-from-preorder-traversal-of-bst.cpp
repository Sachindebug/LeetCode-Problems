//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int arr[],int N) {
        // code here
       vector<int>v;
       stack<int>s;
       s.push(arr[0]);
       for(int i=1;i<N;i++)
       {
           if(arr[i]<s.top())
           s.push(arr[i]);
           else
           {
               int size=s.size();
               int x=s.top();
               while(!s.empty() && arr[i]>s.top())
               s.pop();
               s.push(arr[i]);
               if(size>s.size())
               v.push_back(x);
           }
       }
       v.push_back(s.top());
       return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends