class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0;
        int alpha[26] = {0};
        
        for (char c: allowed)
            alpha[c-'a'] = 1;
        
        bool found = true;
		
        for (string str: words) {
            for (char c: str) 
                if (alpha[c-'a'] == 0) {
                    found = false;
                    break;
                }
            
            if (found)
                cnt++;
            found = true;
        }
		
        return cnt;
    }
};