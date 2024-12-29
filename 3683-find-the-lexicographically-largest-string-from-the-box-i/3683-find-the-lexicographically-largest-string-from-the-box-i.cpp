class Solution {
public:
    string answerString(string word, int count) {
        int n = word.size();
        if(count==1) return word;
        int maxPossibleLength = n-count+1;
        string res = "";
        for(int i = 0;i<=word.size();i++){
            string sub = word.substr(i,maxPossibleLength);
            if(sub>res) res = sub;
        }
        return res;
    }
};