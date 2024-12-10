class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i = 0;i<num.length();i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k-- && !st.empty()) st.pop();
        string res = "";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        int i = 0;
        while(res[i]=='0') i++;
        return res.substr(i).length()>0?res.substr(i):"0";
    }
};