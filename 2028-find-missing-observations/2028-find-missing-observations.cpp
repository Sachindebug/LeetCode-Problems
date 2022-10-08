class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int sz=n;
        n+=m;
        n*=mean;
        int sum=0;
        for(auto x:rolls) sum+=x;
        n-=sum;
        if(n<(sz) || n>(6*sz)) return {};
        int d=n/sz;
        int r=n%sz;
        vector<int> res(sz,d);
        for(int i=0;i<sz;i++)
        {
            if(r>0)
            {
                res[i]++;
                r--;
            }
        }
        return res;
        
    }
};