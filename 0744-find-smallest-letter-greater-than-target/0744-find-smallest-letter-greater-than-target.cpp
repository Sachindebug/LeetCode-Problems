class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(upper_bound(letters.begin(),letters.end(),target)==letters.end()) return letters[0];
        return letters[upper_bound(letters.begin(),letters.end(),target)-letters.begin()];
        
    }
};