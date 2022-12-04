//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

struct node{
    int x, y, w;
    node(int a, int b, int walls){
        x = a;
        y = b;
        w = walls;
    }
};
class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        // code here
        int dir[] = {0,1,0,-1,0};
        int vis[n][m][k+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int l=0;l<k+1;l++){
                    vis[i][j][l] = 0;
                }
            }
        }
        queue<node> q;
        vis[0][0][0] = 1;
        q.push(node(0,0,0));
        int f=0, cnt=0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                node p = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x = p.x+dir[i];
                    int y = p.y+dir[i+1];
                    if(x==n-1 && y==m-1){
                        f=1;break;
                    }
                    if(x<0 || y<0 || x>=n || y>=m) continue;
                    int w = p.w + (mat[x][y]==0?0:1);
                    if(w<=k && vis[x][y][w]==0){
                        q.push(node(x,y,w));
                        vis[x][y][w]=1;
                    }
                }
                if(f==1) break;
            }
            cnt++;
            if(f==1) break;
        }
        if(f==1) return cnt;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends