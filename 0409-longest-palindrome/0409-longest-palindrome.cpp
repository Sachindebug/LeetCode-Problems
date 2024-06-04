class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> ump;
        for(auto x:s)
        {
            ump[x]++;
        }
        int res=0;
        bool one_odd=false;
        for(auto x:ump)
        {
            if((x.second)%2==0)
            {
                res+=(x.second);
            }
            else 
            {
                res+=(x.second-1);
                one_odd=true;
            }
        }
        if(one_odd)
        {
            res++;
        }
        return res;
        
    }
};