class Solution {
public:
    string multiply(string num1, string num2) {
        string res="0";
        int zerocount = 0;
        for(int i = num2.length()-1;i>=0;i--){
            string prod = multiplySingle(num1,num2[i]-'0');
            for(int j = 0;j<zerocount;j++) prod+='0';
            res = addStrings(res,prod,0);
            zerocount++;
        }
        int i = 0;
        while(i<res.length()){
            if(res[i]!='0') break;
            i++;
        }
        if(i==res.length()) return "0";
        return res.substr(i,res.length());
    }
    string multiplySingle(string s, int a){
        int c = 0;
        int i = s.length()-1;
        string res= "";
        while(i>=0){
            int t = s[i]-'0';
            int p = t*a;
            p+=c;
            int cr = p%10;
            c = p/10;
            res+=(cr+'0');
            i--;
        }
        if(c){
            res+=(c+'0');
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string addStrings(string s, string t, int c){
        int n = s.length();
        int m = t.length();
        int i = n-1,j=m-1;
        string res = "";
        while(i>=0 && j>=0){
            int a = s[i]-'0';
            int b = t[j]-'0';
            int cr = (a+b+c)/10;
            int r = (a+b+c)%10;
            res+=(r+'0');
            c = cr;
            i--;
            j--;
        }
        while(i>=0){
            int a = s[i]-'0';
            int cr = (a+c)/10;
            int r = (a+c)%10;
            res+=(r+'0');
            c = cr;
            i--;
        }
        while(j>=0){
            int a = t[j]-'0';
            int cr = (a+c)/10;
            int r = (a+c)%10;
            res+=(r+'0');
            c = cr;
            j--;
        }
        if(c) res+='1';
        reverse(res.begin(),res.end());
        return res;
    }
};