class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                count++;
            }
            else
            {
                if(count==0) ans++;
                else
                {
                    count--;
                }
            }
        }
        ans+=count;
        return ans;
    }
};