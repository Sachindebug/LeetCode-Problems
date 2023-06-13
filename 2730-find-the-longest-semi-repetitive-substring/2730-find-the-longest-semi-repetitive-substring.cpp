class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.length();
        int maxi = 1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=i+1;j<n;j++){
                if(s[j-1]==s[j]){
                    count++;
                }
                if(count<=1){
                    maxi=max(maxi, j-i+1);
                }
            }
        }
        return maxi;
    }
};