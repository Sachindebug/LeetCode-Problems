class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int last_invalid = -1;
        int max_length = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (st.empty()) {
                last_invalid = i;
            } else {
                st.pop();
                if (st.empty()) {
                    max_length = max(max_length, i - last_invalid);
                } else {
                    max_length = max(max_length, i - st.top());
                }
            }
        }
        return max_length;
    }
};