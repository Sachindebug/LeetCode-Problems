class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefixXOR(arr.begin(), arr.end());
        prefixXOR.insert(prefixXOR.begin(), 0);
        int size = prefixXOR.size();

        for (int i = 1; i < size; ++i) prefixXOR[i] ^= prefixXOR[i - 1];

        int count = 0;
        for (int start = 0; start < size; ++start) {
            for (int end = start + 1; end < size; ++end) {
                if (prefixXOR[start] == prefixXOR[end]) {
                    count += end - start - 1;
                }
            }
        }

        return count;
    }
};