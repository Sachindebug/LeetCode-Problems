class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty()) count++;
                else
                {
                    st.pop();
                }
            }
        }
        count+=st.size();
        return count;
    }
};