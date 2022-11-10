class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[s.length()-1]);
        
        for(int i=s.length()-2;i>=0;i--)
        {
            if(st.empty()==false)
            {
               char temp=st.top();
            
               if(temp==s[i])
               {
                st.pop();
               }
                else
            {
                st.push(s[i]);
            }
            }
            
            else
            {
                st.push(s[i]);
            }
        }
        string res="";
        while(st.empty()==false)
        {
            char temp=st.top();
            res+=temp;
            st.pop();
        }
        return res;
        
        
    }
};