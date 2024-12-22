class Solution {
public:
    bool check(string& s, int numOps, int mid, char startChar){
        for(int i = 0; i < s.size(); ++i){
            if(startChar == s[i]) numOps--;
            startChar = (startChar == '0')?'1':'0';
        }
        return (numOps >= 0);
    }
    int solve(string s,int maxmLen,int numOps){
        if(maxmLen == 1) return check(s, numOps, maxmLen, '1') || check(s, numOps, maxmLen, '0');
        int n = s.size();
        int left = 0;
        for(int i = 1;i < n;i++){
            if(s[i] != s[i-1]){
                int len = i - left;
                numOps -= len/(maxmLen+1);
                left = i;
            }
        }
        numOps -= (n-left)/(maxmLen+1);
        return numOps >= 0;
    }
    int minLength(string s, int numOps) {
        int n = s.size(),ans = -1;
        int start = 1,end = n;
        while(start <= end){
            int mid = (start+end)/2;
            if(solve(s,mid,numOps)){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};