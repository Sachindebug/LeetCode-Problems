//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string S, int N)
    {
        // your code here
        int v = 0;
        int c = 0;
        
        vector<int> vow(26, 0);
        vector<int> con(26, 0);
        
        for(int i = 0; i < N; i++) {
            
            if(S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u') {
                v++;
                vow[S[i] - 'a']++;
            }
            else {
                c++;
                con[S[i] - 'a']++;
            }
            
        }
        
       // edges case where Pattern of "ans" is violated
        if(abs(v - c) > 1) return "-1";
        
        vector<int> maxi(26, 0);
        vector<int> mini(26, 0);
        
       // always take maximum element contain vector at first and other as second;
      // according to questions
        if(v >= c) {
            maxi = vow;
            mini = con;
        }
        else {
            maxi = con;
            mini = vow;
        }
        
        int i = 0;
        int j = 0;
        string ans = "";
        
        while(i < 26 && maxi[i] == 0) i++;
        while(j < 26 && mini[j] == 0) j++;
            
            
        while(i < 26 || j < 26) {
            
            if(i < 26) { 
                ans += (i + 'a');
                maxi[i]--;
            }
            
            if(j < 26) { 
                ans += (j + 'a');
                mini[j]--;
            }
            
            while(i < 26 && maxi[i] == 0) i++;
            while(j < 26 && mini[j] == 0) j++;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends