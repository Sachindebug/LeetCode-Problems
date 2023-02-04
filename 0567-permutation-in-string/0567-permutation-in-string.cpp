class Solution {
public:
    bool checkInclusion(string p, string s) {
        vector<int> pv(26,0), sv(26,0), res;
        if(s.size() < p.size())
           return 0;
        
        for(int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i]-'a'];
            ++sv[s[i]-'a'];
        }
        if(pv == sv)
           res.push_back(0);

        for(int i = p.size(); i < s.size(); ++i) 
        {
             
            ++sv[s[i]-'a'];
            
           
            --sv[s[i-p.size()]-'a']; 

            
            if(pv == sv)  
               res.push_back(i-p.size()+1);
        }
        return res.size()>0;
    }
};