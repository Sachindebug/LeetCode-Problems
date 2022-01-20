class Solution {
public:
    int myfun(vector<int> &piles,int s)
    {
        int sum=0;
        for(auto x:piles)
        {
            if(x%s==0) sum+=(x/s);
            else sum+=((x/s)+1);
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        if(h<piles.size()) return -1;
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int res=1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(myfun(piles,m)<=h)
            {
                r=m-1;
            }
            else
            {
                l=m+1;
            }
            
        }
        return l;
        
    }
};