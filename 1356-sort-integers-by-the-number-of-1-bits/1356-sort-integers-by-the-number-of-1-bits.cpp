class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> temp;
        for(auto x:arr)
        {
            int c=countBits(x);
            temp.push_back({x,c});
        }
        sort(temp.begin(),temp.end(),myfun);
        vector<int> res;
        for(auto x:temp)
        {
            res.push_back(x.first);
        }
        return res;
    }
    int countBits(int n)
    {
        int c=0;
        while(n>0)
        {
            
            n=n&n-1;
            c++;
        }
        return c;
    }
    
    static bool myfun(pair<int,int> p1,pair<int,int> p2)
    {
        if(p1.second<p2.second) return true;
        if(p1.second==p2.second && p1.first<p2.first) return true;
        return false;
    }
};