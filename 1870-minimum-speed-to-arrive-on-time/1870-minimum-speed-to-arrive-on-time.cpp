class Solution {
public:
    bool ispossible(vector<int>& dist, double hour, int speed)
    {
         double time = 0.0;
        for (int i = 0 ; i < dist.size(); i++) {
            double t = (double) dist[i] / (double) speed;
            time += (i == dist.size() - 1 ? t : ceil(t));
        }
        return time<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        long long int l=1,r=1e7;
        int res=-1;
        while(l<=r)
        {
            int m = l+(r-l)/2;
            if(ispossible(dist,hour,m))
            {
                res=m;
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return res;
        
    }
};