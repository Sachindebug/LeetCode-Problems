class Solution {
public:
    string largestOddNumber(string num) {
        int i;
        for(i=num.size()-1;i>=0;i--)
        {
            int x=num[i]-'0';
            if(x%2) break;
        }
        string res="";
        for(int j=0;j<=i;j++)
        {
            res+=num[j];
        }
        return res;
    }
};