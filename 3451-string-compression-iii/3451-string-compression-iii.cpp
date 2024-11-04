class Solution {
public:
    string compressedString(string word) {
        string res="";
        int n = word.length();
        int count = 1;
        for(int i = 1;i<word.length();i++)
        {
            if(word[i]==word[i-1])
            {
                count++;
            }
            else
            {
                res+=to_string(count);
                res+=word[i-1];
                count = 1;
            }
            if(count>9)
            {
                res+=to_string(count-1);
                res+=word[i-1];
                count = 1;
            }
        }
        res+=to_string(count);
        res+=word[n-1];
        return res;
    }
};