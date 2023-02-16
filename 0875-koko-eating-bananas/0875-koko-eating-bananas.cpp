class Solution {
public:
    bool ispossible(vector<int>& piles, int m,int h)
    {
        long long int count=0;
        for(auto x:piles)
        {
            count+=(ceil(double(x)/double(m)));
        }
        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int l=1;
        long long int r=1e10;
        int res=-1;
        while(l<=r)
        {
            long long int m=l+(r-l)/2;
            if(ispossible(piles,m,h))
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