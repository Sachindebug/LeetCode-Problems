class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string,int> ump;
        for(auto response: responses){
            set<string> st;
            for(auto res: response){
                if(st.find(res)==st.end()){
                    ump[res]++;
                }
                st.insert(res);
            }
        }
        string res;
        int mx = -1;
        for(auto x: ump){
            if(x.second> mx){
                mx = x.second;
                res = x.first;
            }
        }
        return res;
    }
};