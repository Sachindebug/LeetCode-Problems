class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        vector<int> pos(26,-1);
        vector<bool> inside(26,false);
        for(int i=0;i<s.length();i++) pos[s[i]-'a']=i;
        for(int i=0;i<s.length();i++)
        {
            while(!st.empty() && st.top()>s[i] && !inside[s[i]-'a'])
            {
                char c=st.top();
                if(pos[c-'a']>i)
                {
                    st.pop();
                    inside[c-'a']=false;
                }
                else
                {
                    break;
                }
            }
            if(!inside[s[i]-'a'])
            {
                st.push(s[i]);
                inside[s[i]-'a']=true;
            }
            
            
        }
        string res="";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};