class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++)
        {
            int x=__builtin_popcount(i);
            res.push_back(x);
        }
        return res;
    }
};