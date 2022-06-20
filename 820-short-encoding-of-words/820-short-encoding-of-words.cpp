class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s;
        for(auto x:words)
        {
            s.insert(x);
        }
        string t="";
        string temp;
        for(auto x:s)
        {
            t="";
            for(int i=x.length()-1;i>=1;i--)
            {
                t+=x[i];
                temp=t;
                reverse(temp.begin(),temp.end());
                if(s.find(temp)!=s.end())
                {
                    s.erase(temp);
                }
            }
            
            
        }
        int res=0;
        for(auto x:s)
        {
            res+=(1+x.length());
        }
        
        return res;
    }
};