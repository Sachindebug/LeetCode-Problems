class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
           vector<int>ans;
           unordered_map<int,int> mpp;
           vector<vector<int> >gr(n+1,vector<int>(n+1,1e9));
           for(int i=1; i<n; i++){
              gr[i][i]=0;
              gr[i+1][i+1]=0;
              gr[i][i+1]=1;
              gr[i+1][i]=1;
           }
           if(x!=y){
               gr[x][y]=1;
               gr[y][x]=1;
           }
           for(int k=1; k<=n; k++){
              for(int i=1; i<=n; i++){
                  for(int j=1; j<=n; j++){
                      gr[i][j]=min(gr[i][j],gr[i][k]+gr[k][j]);
                  }
              }
           }
           for(int i=1; i<=n; i++){
               for(int j=1; j<=n; j++){
                   mpp[gr[i][j]]++;
               }
           }
           for(int i=1; i<=n; i++){
               ans.push_back(mpp[i]);
           }
           return ans;
    }
};