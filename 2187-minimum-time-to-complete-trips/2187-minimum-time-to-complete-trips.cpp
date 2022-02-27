class Solution {
public:
    long long minimumTime(vector<int>& time, int tt) {
        long long int l=1;
        long long int r=1e14;
        long long int res=-1;
        while(l<=r)
        {
            long long int m=l+(r-l)/2;
            if(ispossible(time,m,tt))
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
    bool ispossible(vector<int>& time,long long int m,int tt)
    {
        long long int n=time.size();
        long long int res=0;
        for(int i=0;i<n;i++)
        {
            res+=(m/time[i]);
        }
        return res>=tt;
    }
};