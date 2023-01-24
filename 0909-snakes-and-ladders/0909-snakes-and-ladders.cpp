class Solution {
public:
    pair<int,int> findcor(int curr,int n){
        int r=n-(curr-1)/n -1;
        int c=(curr-1)%n;
        if(r%2==n%2){
            return {r,n-1-c};
        }
        else{
            return {r,c};
        }
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int cnt=0;
        queue<int> q;
        vector<vector<bool>> vis(n, vector<bool> (n,false));
        q.push(1);
        vis[n-1][0]=true;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int x=q.front();
                q.pop();
                if(x==n*n){
                    return cnt;
                }
                for(int k=1;k<=6;k++){
                    if(k+x>n*n){
                        break;
                    }
                    pair<int,int> p=findcor(k+x,n);
                    int r=p.first;
                    int c=p.second;
                    if(vis[r][c]==true){
                        continue;
                    }
                    vis[r][c]=true;
                    if(board[r][c]==-1){
                        q.push(k+x);
                    }
                    else{
                        q.push(board[r][c]);
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};