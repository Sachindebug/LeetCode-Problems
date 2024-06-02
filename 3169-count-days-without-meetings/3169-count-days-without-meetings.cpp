class Solution {
public:
    int countDays(int n, vector<vector<int>>& q) {
        sort(q.begin(),q.end());
        int res = 0;
        int p = q.size();
        int mxright = -1;
        res+=max(0,q[0][0]-1);
        for(int i = 1;i<q.size();i++)
        {
            int prev = q[i-1][1];
            mxright = max(mxright,prev);
            int curr = q[i][0];
            if(mxright>=curr) continue;
            else res+=(curr-mxright-1);
        }
        mxright = max(mxright,q[p-1][1]);
        res+=max(0,n-mxright);
        return res;
    }
};