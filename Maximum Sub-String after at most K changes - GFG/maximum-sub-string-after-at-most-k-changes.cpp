//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int distincts(int mp[], int ws){
            int maxi = 0;
            for(int i=0;i<26;i++) maxi = max(maxi, mp[i]);
            return ws-maxi;
    }
    	
    int characterReplacement(string s, int k){
    	   // Code here
    	        int st=0, ans=k+1;
                int mp[26] = {0};
                for(int i=0; i<=k; i++){
                    mp[s[i]-'A']++;
                }
                
                for(int  i=k+1; i<s.size(); i++){
                    mp[s[i]-'A']++;
                    while(i<s.size() && distincts(mp, i-st+1) > k){
                        mp[s[st]-'A']--;
                        st++;
                    }
                    
                    ans = max(ans, i-st+1);
                }
                
                return ans;
    }  // Code here
		

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends