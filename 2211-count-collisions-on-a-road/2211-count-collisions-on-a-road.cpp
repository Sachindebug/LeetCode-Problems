class Solution {
public:
    int countCollisions(string s) {
        int idx1=-1;
        int idx2=-1;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R' || s[i]=='S')
            {
                idx1=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='L' || s[i]=='S')
            {
                idx2=i;
                break;
            }
        }
        if(idx1==-1 || idx2==-1 || idx1>idx2) return 0;
        int count=0;
        for(int i=idx1;i<=idx2;i++)
        {
            if(s[i]=='L' || s[i]=='R') count++;
        }
        return count;
    }
};