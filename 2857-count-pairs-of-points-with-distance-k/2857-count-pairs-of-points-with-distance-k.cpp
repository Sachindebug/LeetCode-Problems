class Solution {
public:
    int countPairs(vector<vector<int>>& c, int k) {
        int n = c.size();
        int cx, cy, minx, maxx;
        int res = 0;
        map<pair<int,int>,int> mp;
        for(auto p : c)
        {
            mp[{p[0],p[1]}]++;
        }
        for(int i = 0; i < n; i++)
        {
            cx = c[i][0];
            cy = c[i][1];
            mp[{cx,cy}]--;
            for(int i = 0; i <= k; i++)
            {
                int x = cx^i;
                int y = (k-i)^cy;
                if(mp.find({x,y}) != mp.end())
                {
                    res+=mp[{x,y}];
                }
            }
        }
        return res;
    }
};