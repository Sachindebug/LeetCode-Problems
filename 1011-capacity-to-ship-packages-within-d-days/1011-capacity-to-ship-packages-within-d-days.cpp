class Solution {
public:
    bool ispossible(vector<int> &arr,int m, int k)
    {
        int sum=0;
        int count=0;
        for(auto x:arr)
        {
            if(x>m) return false;
            if(sum+x<=m) sum+=x;
            else
            {
                count++;
                sum=x;
            }
            
        }
        count++;
        return count<=k;
    }
    int shipWithinDays(vector<int> &arr, int d) {
        int l=0;
        int r=1e9;
        int res=-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(ispossible(arr,m,d))
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