class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res="";
        stack<char> st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]==')')
            {
                if(s[i]=='(')
                {
                    res+=s[i];
                    st.push(s[i]);
                }
                else
                {
                    if(!st.empty())
                    {
                        char c=st.top();
                        
                        if(c=='(')
                        {
                           st.pop();
                           res+=s[i];
                        }
                    }
                   
                }
                
            }
            else
            {
                res+=s[i];
            }
        }
        int count=st.size();
        string res1="";
        for(int i=res.size()-1;i>=0;i--)
        {
            if(count>0 && res[i]=='(')
            {
                count--;
            }
            else
            {
                res1+=res[i];
            }
            
        }
        reverse(res1.begin(),res1.end());
        return res1;
    }
};