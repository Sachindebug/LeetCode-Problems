class Solution {
public:
    int minimumChairs(string s) {
        int e = 0;
        int res=0;
        for(auto x:s)
        {
            e+=(x=='E');
            e-=(x=='L');
            res = max(res,e);
        }
        return res;
    }
};