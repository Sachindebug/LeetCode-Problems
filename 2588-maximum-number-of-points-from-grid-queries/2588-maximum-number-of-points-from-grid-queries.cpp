class Solution{
public:
    bool valid(int i,int j,int n,int m){
        return i>=0 and j>=0 and i<n and j<m;
    }
    vector<int> maxPoints(vector<vector<int>>& nums,vector<int>& queries){
        int n=nums.size();
        int m=nums[0].size();
        vector<int> ans(queries.size());
        vector<pair<int,int>> q(queries.size());
        for(int i=0;i<queries.size();i++){
            q[i] = { queries[i] , i };
        }
		sort(q.begin(),q.end());
        vector<vector<int>> vis(n,vector<int>(m,-1));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        pq.push({nums[0][0],{0,0}});
        vis[0][0] = 1;
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        int count = 0;
        for(int i=0;i<queries.size();i++){
            while(pq.size() and pq.top().first < q[i].first){
                count++;
                int x = pq.top().second.first;
                int y = pq.top().second.second;
                pq.pop();
                for(int j=0;j<4;j++){
                    int newx = dx[j] + x;
                    int newy = dy[j] + y;
                    if(valid(newx,newy,n,m) and vis[newx][newy]==-1){
                        vis[newx][newy] = 1;
                        pq.push({nums[newx][newy],{newx,newy}});
                    }
                }
            }
            ans[q[i].second] = count; 
        }
        return ans;
    }
};
