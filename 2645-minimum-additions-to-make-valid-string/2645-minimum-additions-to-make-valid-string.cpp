class Solution {
public:
    int addMinimum(string word) {
        int n = word.size(), i = 0, curr = 0, result = 0;
        while (i < n || curr) {
            if (i < n && word[i] - 'a' == curr) {
                i++;
            } else {
                result++;
            }
            curr = (curr + 1) % 3;
        }
        return result;
    }
};