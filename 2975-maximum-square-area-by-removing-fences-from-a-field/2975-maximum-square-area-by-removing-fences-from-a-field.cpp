class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hf, vector<int>& vf) {
        
        vector<int> vgaps;
        vector<int> hgaps;
        
        hf.push_back(m); hf.push_back(1);
        vf.push_back(n); vf.push_back(1);
        
        sort(vf.begin(),vf.end());
        sort(hf.begin(),hf.end());
                
        for(int i=0; i<vf.size()-1; ++i)
            for(int j=i+1; j<vf.size(); ++j)            
                hgaps.push_back(vf[j] - vf[i]);
        for(int i=0; i<hf.size()-1; ++i)
            for(int j=i+1; j<hf.size(); ++j)
                vgaps.push_back(hf[j] - hf[i]);
        
        long long res = -1;
        
        sort(vgaps.begin(), vgaps.end());
        unordered_map<int,int> hm;
        
        for(int i=0; i<hgaps.size(); ++i)
            hm[hgaps[i]] = 1;
        
        for(int i=vgaps.size()-1; i>=0; --i)
        {
            if(hm[vgaps[i]]  == 1)
            {
                long long l = vgaps[i];
                res = l*l;
                res = res%1000000007;
                break;
            }
        }

        return res;
    }
};