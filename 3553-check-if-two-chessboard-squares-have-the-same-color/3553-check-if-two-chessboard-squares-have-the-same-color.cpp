class Solution {
public:
    bool checkTwoChessboards(string s1, string s2) {
        int a = s1[0]-'a';
        int b = s1[1]-'0';
        int c = s2[0]-'a';
        int d = s2[1]-'0';
        return (a+b)%2==(c+d)%2;
    }
};