class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        int j = 0;
        int n = str1.length();
        int m = str2.length();
        if(n<m) return false;
        while(i<n && j<m){
            if(str1[i]==str2[j] || (str2[j]-str1[i]+26)%26==1){
                j++;
            }
            i++;
        }
        return j==m;
    }
};