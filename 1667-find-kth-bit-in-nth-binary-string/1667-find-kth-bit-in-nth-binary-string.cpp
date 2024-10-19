class Solution {
public:
    char findKthBit(int n, int k) {
        string res = recurse(n-1);
        return res[k-1];
    }
    string recurse(int n){
        if(n==0) return "0";
        string temp = recurse(n-1);
        string invert = "";
        for(auto x:temp){
            if(x=='1') invert+='0';
            else invert+='1';
        }
        string res = temp;
        res+='1';
        reverse(invert.begin(),invert.end());
        res+=invert;
        return res;
    }
};