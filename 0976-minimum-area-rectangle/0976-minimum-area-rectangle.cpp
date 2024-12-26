class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        if (points.size() < 4)
            return 0;
        int minArea = INT_MAX;
        set<vector<int>> pointSet;
        for (auto point : points) 
            pointSet.insert(point);
        for (int i = 0; i < points.size(); i++) {
            for (int j = i+1; j < points.size(); j++) {
                int xOne = points[i][0], yOne = points[i][1];
                int xTwo = points[j][0], yTwo = points[j][1];

                if (xOne != xTwo && yOne != yTwo && xOne != yTwo && yOne != xTwo) {
                    if (pointSet.count({ xOne, yTwo }) && pointSet.count({ xTwo, yOne })) {
                        int curArea = (abs(xTwo-xOne) * abs(yTwo-yOne));
                        minArea = min(minArea, curArea);
                    }
                }
            }
        }
        return minArea == INT_MAX ? 0 : minArea;
    }
};