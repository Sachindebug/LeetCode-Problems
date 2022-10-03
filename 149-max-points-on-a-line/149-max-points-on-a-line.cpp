class Solution {
public:
    bool collinear(int x1,int y1,int x2,int y2,int x3,int y3)
    {
        if((y3 - y2) * (x2 - x1) == (y2 - y1) * (x3 - x2)) return true;
        return false;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int res=1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                int count=0;
                for(int k=0;k<n;k++)
                {
                    int x3=points[k][0];
                    int y3=points[k][1];
                    if(collinear(x1,y1,x2,y2,x3,y3)) count++;
                }
                res=max(res,count);
            }
        }
        return res;
    }
};