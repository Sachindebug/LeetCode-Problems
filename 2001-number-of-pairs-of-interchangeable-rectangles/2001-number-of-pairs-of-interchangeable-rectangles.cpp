class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> ump;
        for(auto x:rectangles)
        {
            int a=x[0];
            int b=x[1];
            int g=__gcd(a,b);
            a/=g;
            b/=g;
            ump[{a,b}]++;
        }
        long long res=0;
        for(auto x:ump)
        {
            long long int b=x.second;
            res+=(b*(b-1))/2;
        }
        return res;
    }
};