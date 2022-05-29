class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<vector<int>> freq(n,vector<int> (26,0));
        for(int i=0;i<n;i++)
        {
            string s=words[i];
            for(int j=0;j<s.length();j++)
            {
                freq[i][s[j]-'a']++;
            }
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x=words[i].length();
                int y=words[j].length();
                bool flag=true;
                for(int k=0;k<26;k++)
                {
                    if(freq[i][k]>0 && freq[j][k]>0) flag=false;
                }
                if(flag)
                {
                    res=max(res,x*y);
                }
            }
        }
        return res;
    }
};