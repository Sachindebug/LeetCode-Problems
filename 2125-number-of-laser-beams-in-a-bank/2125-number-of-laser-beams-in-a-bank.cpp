class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res=0;
        int prev=0;
        for(auto x:bank)
        {
            int c=count(x.begin(),x.end(),'1');
            if(c>0)
            {
                res+=(prev*c);
                prev=c;
            }
                
        
        }
        return res;
        
    }
};