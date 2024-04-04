class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int mx=0;
        for(int i=0;i<s.length();i++)
        {
            
            if(s[i]=='(')
            {
                st.push(s[i]);
                if((st.size())>mx)
            {
                mx=st.size();
            }
            }
            else if(s[i]==')')
            {
                st.pop();
            }
        }
        return mx;
    }
};