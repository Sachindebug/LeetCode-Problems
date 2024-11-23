class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> res(n, vector<char>(m));
        // Trasposing the matrix
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                res[i][m - 1 - j] = box[j][i];
            }
        }
        // Applying the gravity
        for (int i = 0; i < m; i++) {
            int start = n - 1;
            for (int j = start; j >= 0; j--) {
                if (res[j][i] == '*') {
                    start = j - 1;
                } else if (res[j][i] == '#') {
                    res[j][i] = '.';
                    res[start][i] = '#';
                    start--;
                }
            }
        }
        return res;
    }
};