class Solution {
public:
    string decodeAtIndex(string s, int k,long long len =0) {
        for (auto i = 0; i < s.size(); ++i) {
                if (isalpha(s[i])) {
                    if (++len == k) return string(1, s[i]);

                }
                else {
                    if (len * (s[i] - '0') >= k) return decodeAtIndex(s, k % len == 0 ? len : k % len);
                    len *= s[i] - '0';
                }
            }
            
            return 0;
    }
};