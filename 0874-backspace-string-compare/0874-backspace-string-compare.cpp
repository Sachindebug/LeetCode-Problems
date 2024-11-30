class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.length(), m = t.length();
        int i = n-1,j = m-1;
        int sSkip = 0, tSkip = 0;
        while(i>=0 || j>=0){
            while(i>=0){
                if(s[i]=='#') {
                    sSkip++;
                    i--;
                }
                else if(sSkip > 0){
                    sSkip--;
                    i--;
                }
                else break;
            }
            while(j>=0){
                if(t[j]=='#') {
                    tSkip++;
                    j--;
                }
                else if(tSkip > 0){
                    tSkip--;
                    j--;
                }
                else break;
            }
            if(i>=0 && j>=0 && s[i]!=t[j]) return false;
            if(i<0 && j<0) return true;
            if(i<0 || j<0) return false;
            i--;
            j--;
        }
        return true;
    }
};