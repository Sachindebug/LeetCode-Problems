class Solution {
public:
    
    int numberOfSubstrings(string s) {
         int a = 0, b = 0, c = 0 ,j = 0 , ans = 0;
        int n=s.length();
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'a')
                a++;
            else if(s[i] == 'b')
                b++;
            else
                c++;

            if(a > 0 && b > 0 && c > 0)
            {
                while(a > 0 && b > 0 && c > 0)
                {
                    ans+= n - i;
                    if(s[j] == 'a')
                        a--;
                    if(s[j] == 'b')
                        b--;
                    if(s[j] == 'c')
                        c--;
                    j++;
                }
            }
        }
        return ans;
    
    }
};