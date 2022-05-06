class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push({s[i],1});
            }
            else
            {
                char x=st.top().first;
                int  y=st.top().second;
                if(s[i]==x)
                {
                    if(y==k-1)
                    {
                       for(int i=1;i<k;i++)
                       {
                           st.pop();
                       }
                    }
                    else
                    {
                        st.push({s[i],y+1});
                    }
                }
                else
                {
                    st.push({s[i],1});
                }
            }
        }
        string res="";
        while(!st.empty())
        {
            char c=st.top().first;
            res+=c;
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};