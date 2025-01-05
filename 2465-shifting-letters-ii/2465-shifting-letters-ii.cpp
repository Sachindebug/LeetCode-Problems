class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> count(n,0);
        for(auto x: shifts){
            int start = x[0];
            int end = x[1];
            int dir = x[2];
            if(dir==0){
                count[start]-=1;
                if(end+1<n) count[end+1]+=1;
            }
            else{
                count[start]+=1;
                if(end+1<n) count[end+1]-=1;
            }
        }
        int sum = 0;
        for(int i = 0;i<s.length(); i++){
            sum+=count[i];
            int pos = s[i]-'a';
            int nextChar = 'a' + (pos+(sum%26)+26)%26;
            s[i] = nextChar;
        }
        return s;
    }

    /*
        * [0,0,0]
        * [-1,1,0]
        * [-1,2,1]
        * [0,3,2]
    */
};