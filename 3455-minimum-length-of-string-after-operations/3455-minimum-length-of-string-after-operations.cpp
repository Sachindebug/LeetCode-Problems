class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26,0);
        for(auto x: s) freq[x-'a']++;
        int res = 0;
        for(auto count: freq){
            if(count > 0) {
                if(count%2==0) res+=2;
                else res++;
            }
        }
        return res;
    }
};