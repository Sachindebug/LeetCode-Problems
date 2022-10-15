//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        queue<pair<int, int>> q;
        q.push(source);
        int dir[5] = {0, 1, 0, -1, 0};
        int distance = 0, n = grid.size(), m = grid[0].size(); 
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int x = q.front().first, y = q.front().second;
                q.pop();
                if(x == destination.first && y == destination.second){
                    return distance;
                }
                for(int d = 0; d < 4; d++){
                    int nx = x + dir[d], ny = y + dir[d + 1];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == 0) continue;
                    q.push({nx, ny});
                    grid[nx][ny] = 0;
                }
            }
            distance++;
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends