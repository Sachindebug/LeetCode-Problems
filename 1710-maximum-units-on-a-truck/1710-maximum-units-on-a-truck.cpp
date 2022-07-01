class Solution {
public:
    int maximumUnits(vector<vector<int>>& arr, int cap) {
        sort(arr.begin(),arr.end(),myfun);
        int res=0;
        for(auto x:arr)
        {
            int a=x[0];
            int b=x[1];
            if(cap>=a)
            {
                res+=(a*b);
                cap-=a;
            }
            else
            {
                res+=(cap*b);
                break;
            }
        }
        return res;
        
        
    }
    static bool myfun(vector<int> &a,vector<int> &b)
    {
        return b[1]<a[1];
    }
};