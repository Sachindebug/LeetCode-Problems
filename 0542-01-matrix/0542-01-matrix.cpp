class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int a=p.first;
            int b=p.second;
            if(a>0 && dis[a-1][b]>1+dis[a][b])
            {
                dis[a-1][b]=1+dis[a][b];
                q.push({a-1,b});
            }
            if(b>0 && dis[a][b-1]>1+dis[a][b])
            {
                dis[a][b-1]=1+dis[a][b];
                q.push({a,b-1});
            }
            if(a<n-1 && dis[a+1][b]>1+dis[a][b])
            {
                dis[a+1][b]=1+dis[a][b];
                q.push({a+1,b});
            }
            if(b<m-1 && dis[a][b+1]>1+dis[a][b])
            {
                dis[a][b+1]=1+dis[a][b];
                q.push({a,b+1});
            }
                                              
        }
        return dis;
    }
};