class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();
        unordered_map<int,int> ump;
        if(n<k) return false;
        if(n==k) return true;
        for(auto x:s) ump[x]++;
        
        
        int odd=0;
        int even=0;
        for(auto x:ump)
        {
            if(x.second%2) odd++;
            else even++;
        }
        if(odd<=k) return true;
        return false;
    }
};