// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isSafe(int i, int j, int n) {
        if(i >= 0 && j >= 0 && i < n && j < n) return true;
        return false;
    }
    
    bool helper(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &res) {
        int n = mat.size();
        if(isSafe(i, j, n) == false) return false;
        
        if(i == n-1 && j == n-1) {
            res[i][j] = 1;
            return true;
        }
        
        if(mat[i][j] == 0) return false;
        if(res[i][j] == 1) return false;
        
        res[i][j] = 1;
        
        int val = mat[i][j];
        for(int add = 1; add <= val; add++) {
            if(helper(i, j + add, mat, res)) {
                return true;
            }
            if(helper(i + add, j, mat, res)) {
                return true;
            }
        }
        
        res[i][j] = 0;
        return false;
    }

	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   int n = matrix.size();
	   vector<vector<int>> res(n, vector<int>(n, 0));
	   if(helper(0, 0, matrix, res)) {
	       return res;
	   } else {
	       return {{-1}};
	   }
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends