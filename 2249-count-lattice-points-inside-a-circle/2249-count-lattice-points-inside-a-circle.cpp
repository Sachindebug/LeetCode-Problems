class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>> s;
        for(auto x:circles)
        {
            int x1 = x[0];
            int y1 = x[1];
            int r = x[2];
            for(int i=x1-r;i<=x1+r;i++)
            {
                for(int j=y1-r;j<=y1+r;j++)
                {
                    if(sqrt((x1-i)*(x1-i) + (y1-j)*(y1-j))<=r)
                       {
                           s.insert({i,j});
                       }
                }
            }
        }
        return s.size();            
    }
};