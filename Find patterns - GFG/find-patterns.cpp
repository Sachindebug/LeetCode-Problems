//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        // code here 
        int ct=0;
        for(int i=0;i<S.length();i++){
            
            if(S[i]!=W[0]) continue;
            int j,k=0;
            for( j=i;j<S.length();j++){
                if(S[j]==W[k]){
                    S[j]='*';
                    k++;
                    
                }
                if(k == W.length()){ct++; break; }
              
            }
           
        }
        return ct;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends