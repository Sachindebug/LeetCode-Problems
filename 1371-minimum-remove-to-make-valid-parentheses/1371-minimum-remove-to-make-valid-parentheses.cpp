class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res="",res1="";
        int open = 0, close = 0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]==')'){
                if(s[i]=='('){
                    res+=s[i];
                    open++;
                }
                else{
                    if(open>0){
                        open--;
                        res+=s[i];
                    }
                }  
            }
            else res+=s[i];
        }
        for(int i=res.size()-1;i>=0;i--){
            if(open>0 && res[i]=='('){
                open--;
            }
            else res1+=res[i];
        }
        reverse(res1.begin(),res1.end());
        return res1;
    }
};