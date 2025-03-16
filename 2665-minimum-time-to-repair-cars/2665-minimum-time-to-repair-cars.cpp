class Solution {
public:
    bool ispossible(vector<int>& ranks, int cars, long long int m)
    {
        long long int count=0;
        for(int i=0;i<ranks.size();i++)
        {
            long long int x=ranks[i];
            long long int p=m/x;
            long long int q=sqrt(p);
            count+=q;
        }
        return count>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long int l=1,r=1e14,res=-1;
        
        while(l<=r)
        {
            long long int m=l+(r-l)/2;
            if(ispossible(ranks,cars,m))
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