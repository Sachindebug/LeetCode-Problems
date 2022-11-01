//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here  
        int m = 0;
        for (int i=30; i>=0; i--) {
            int mc = m | 1<<i;
            int x = 0;
            for (int j=0; j<R; j++) {
                int xc = 0;
                for (int k=C/2; k>0; k/=2)
                    while (xc+k < C && matrix[j][xc+k] < mc) xc += k;
                if (matrix[j][xc] < mc) xc++;
                x += xc;
            }
            if (x <= (R*C)/2)
                m = mc;
        }
        return m;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends