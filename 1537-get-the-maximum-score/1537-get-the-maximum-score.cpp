class Solution {
public:
    int maxSum(vector<int>& A, vector<int>& B) {
        long long M = A.size(), N = B.size(), X = 0, Y = 0, prevX = 0, prevY = 0, mod = 1e9+7, i = 0, j = 0;
        while (i < M && j < N) {
            if (A[i] < B[j]) X += A[i++];
            else if (A[i] > B[j]) Y += B[j++];
            else X = Y = max(prevX + A[i++], prevY + B[j++]);
            prevX = X;
            prevY = Y;
        }
        while (i < M) X += A[i++];
        while (j < N) Y += B[j++];
        return max(X, Y) % mod;
    }
};