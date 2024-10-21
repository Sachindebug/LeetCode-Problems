class Solution {
public:
    int maxUniqueSplit(string s) {
        set<string> seen;
        int maxCount = 0;
        backtrack(s, 0, seen, 0, maxCount);
        return maxCount;
    }
    void backtrack(string& s, int start, set<string>& seen, int count, int& maxCount) {
        if (start == s.size()) {
            maxCount = max(maxCount, count);
            return;
        }
        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);
                backtrack(s, end, seen, count + 1, maxCount);
                seen.erase(substring);
            }
        }
    }
};