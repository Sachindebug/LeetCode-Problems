class Solution {
public:
    int maxScore(string s) {
        int oneCount = 0;
        for(auto c: s) oneCount+=(c=='1');
        int maxScore = 0;
        int currentOneCount = 0;
        for(int i = 0;i<s.size()-1;i++){
            currentOneCount+=(s[i]=='1');
            int zeroCount = i-currentOneCount+1;
            maxScore = max(maxScore,zeroCount + (oneCount-currentOneCount));
        }
        return maxScore;
    }
};