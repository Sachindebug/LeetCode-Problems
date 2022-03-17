class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int n=s.length();
        if(n==0) return 0;
        if(n==2) return 1;
        string between="";
        string after="";
        int closingIndex;
        stack<char> st;
        //processing
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') st.push(s[i]);
            else st.pop();
            if(st.empty()) 
            {
                closingIndex=i;
                break;
            }
        }
        
        for(int i=1;i<closingIndex;i++) between+=s[i];
        for(int i=closingIndex+1;i<n;i++) after+=s[i];
        if(between=="") return 1+scoreOfParentheses(after);
        return (2*scoreOfParentheses(between))+scoreOfParentheses(after); 
    }
};