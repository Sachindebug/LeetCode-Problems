class Solution {
public:
    int numberOfWays(string corridor) {
       int MOD = 1000000007;
        vector<int> indices;
        for (int index = 0; index < corridor.length(); index++) {
            if (corridor[index] == 'S') {
                indices.push_back(index);
            }
        }
        if (indices.size() == 0 || indices.size() % 2 == 1) {
            return 0;
        }
        long count = 1;
        int previousPairLast = 1;
        int currentPairFirst = 2;
        while (currentPairFirst < indices.size()) {
            count *= (indices[currentPairFirst] - indices[previousPairLast]);
            count %= MOD;
            previousPairLast += 2;
            currentPairFirst += 2;
        }
        return (int) count;
    }
};