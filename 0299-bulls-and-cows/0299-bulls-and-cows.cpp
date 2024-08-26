class Solution {
public:
    string getHint(string s, string t) {
        int n = s.length(); 
        int count1 = 0;
        int count2 = 0;
        unordered_map<char,int> ump;
        for(int i = 0;i<n;i++){
            if(s[i]==t[i]) count1++;
            else ump[s[i]]++;
        }
        for(int i =0;i<n;i++){
            if(s[i]!=t[i]){
                if(ump.find(t[i])!=ump.end() && ump[t[i]] > 0) {
                    count2++;
                    ump[t[i]]--;
                }
            }
        }
        string res = "";
        res+=to_string(count1);
        res+='A';
        res+=to_string(count2);
        res+='B';
        return res;
    }
};