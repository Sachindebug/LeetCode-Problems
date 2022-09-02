class Solution {
public:
    int minSwaps(string s) {
        int n1e = 0, n1o = 0, n = s.size();
        
        for (int i = 0; i < n; i += 2) {
            n1e += s[i] == '1';
        }
        
        // Number of '1' at odd position
        for (int i = 1; i < n; i += 2) {
            n1o += s[i] == '1';   
        }
        
        // If length is odd ==> It should be: 10101 or 01010
        if (n % 2 == 1) {
            
            // 01010 case
            if (n1e + n1o == n / 2) {
                return n1e;
            } else if (n1e + n1o == n / 2 + 1) { // 10101 case
                return n1o;
            }
        } else {
            // Should be 010101 or 101010
            if (n1e + n1o == n/2)
                return min(n1e, n1o);
        }
        
        return -1;
    }
};