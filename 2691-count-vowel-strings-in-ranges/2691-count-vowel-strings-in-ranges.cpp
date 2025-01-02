class Solution {
public:
    bool isvowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        {
            return true;
        }
        return false;
    }
    bool check(string s)
    {
        int n=s.length();
        char a=s[0];
        char b=s[n-1];
        if(isvowel(a) && isvowel(b)) return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> temp;
        int count=0;
        for(auto x:words)
        {
            if(check(x)) count++;
            temp.push_back(count);
        }
        vector<int> res;
        for(auto x:queries)
        {
            int l=x[0];
            int r=x[1];
            if(l==0)
            {
                res.push_back(temp[r]);
            }
            else
            {
                res.push_back(temp[r]-temp[l-1]);
            }
        }
        return res;
    }
};