class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        
        set<pair<int,int>> s;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                int x=j;
                int y=i;
                int g=__gcd(x,y);
                x/=g;
                y/=g;
                if(s.find({x,y})==s.end())
                {
                    s.insert({x,y});
                    
                }
            }
        }
        for(auto x:s)
        {
            int a=x.first;
            int b=x.second;
            string temp="";
            temp+=to_string(a);
            temp+='/';
            temp+=to_string(b);
            res.push_back(temp);
        }
        return res;
        
    }
};