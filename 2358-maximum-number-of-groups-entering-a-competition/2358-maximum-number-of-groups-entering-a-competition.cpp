class Solution {
public:
    int maximumGroups(vector<int>& arr) {
       int k = 0, total = 0, n = arr.size();
        while (total + k + 1 <= n)
            total += ++k;
        return k;
        
    }
};