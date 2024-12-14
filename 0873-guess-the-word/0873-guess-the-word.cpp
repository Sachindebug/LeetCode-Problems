/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int numMatches(const string& s1, const string& s2) {
        int matches = 0;
        for (int index = 0; index < s1.length(); index++) {
            if (s1[index] == s2[index]) {
                matches++;
            }
        }
        return matches;
    }
    void findSecretWord(vector<string>& words, Master& master) {
        unordered_set<string> prospects(words.begin(), words.end());
        while (!prospects.empty()) {
            string frontWord = *prospects.begin();
            int numMatchesSecret = master.guess(frontWord);
            for (auto it = prospects.begin(); it != prospects.end();) {
                if (numMatches(*it, frontWord) != numMatchesSecret) {
                    it = prospects.erase(it);
                } else {
                    ++it; 
                }
            }
            prospects.erase(frontWord);
        }
    }
};