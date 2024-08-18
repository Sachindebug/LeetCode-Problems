class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& res) {
        int n = res.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && res[i] >= res[st.top()]) {
                st.pop();
                ++ans[i];
            }
            if (!st.empty())
                ++ans[i];
            st.push(i);
        }
        return ans;
    }
};