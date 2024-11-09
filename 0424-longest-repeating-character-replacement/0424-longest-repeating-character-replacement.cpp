class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        for(int i = 0;i<=25;i++){
            char c = 'A'+i;
            ans = max(ans,maxSameLength(s,k,c));
        }
        return ans;
    }
    int maxSameLength(const string &s, int k, char c) {
        int maxLen = 0;
        int left = 0;
        int remainingK = k;
        for (int right = 0; right < s.size(); right++) {
            if (s[right] != c) {
                remainingK--;
            }
            while (remainingK < 0) {
                if (s[left] != c) {
                    remainingK++;
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};