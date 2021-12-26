class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        int d;
        map<int,vector<vector<int>>> ump;
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            d=x*x+y*y;
            ump[d].push_back(points[i]);

        }
        
        for(auto x:ump)
        {
            
            for(auto ele:x.second)
            {
                if(k>0)
                    res.push_back(ele);
                k--;
            }
        }
        
        return res;
        
    }
};