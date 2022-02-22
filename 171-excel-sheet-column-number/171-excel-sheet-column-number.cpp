class Solution {
public:
    int titleToNumber(string s) {
        long long int p=1;
        int n=s.length();
        int j=n-1;
        long long int res=0;
        while(j>=0)
        {
            res=res+(((s[j]-'A')+1)*p);
            p*=26;
            j--;
        }
        return res;
    }
    
};