class Solution {
public:
    int myAtoi(string s) {
        long long res=0;
        int idx=0;
        while(idx<s.length() && s[idx]==' ')
        {
            idx++;
        }
        bool neg=false;
        if(idx<s.length() && s[idx]=='-')
        {
            neg=true;
            idx++;
        }
        else if(idx<s.length() && s[idx]=='+')
        {
            idx++;
        }
        while(idx<s.length())
        {
            if(res>INT_MAX)
            {
                if(neg) return INT_MIN;
                return INT_MAX;
            }
            
            char c=s[idx];
            if(c>='0'&& c<='9')
            {
                res=res*10+(c-'0');
                idx++;
            }
            else break;
            
        }
        if(neg) res*=-1;
        if(res>INT_MAX) return INT_MAX;
        if(res<INT_MIN) return INT_MIN;
        return res;
    }
};