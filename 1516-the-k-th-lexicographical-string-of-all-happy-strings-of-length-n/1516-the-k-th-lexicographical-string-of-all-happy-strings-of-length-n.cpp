class Solution {
public:
    map<char,vector<char>> ump;
    string getHappyString(int n, int k) {
        string temp = "";
        vector<string> res;
        ump['a'] = {'b','c'};
        ump['b'] = {'a','c'};
        ump['c'] = {'b','a'};
        recurse(temp,res,n);
        sort(res.begin(),res.end());
        if(res.size()<k) return "";
        return res[k-1];
    }

    void recurse(string &curr, vector<string> &res, int n){
        if(n==0){
            res.push_back(curr);
            return;
        }
        if(curr==""){
            for(int i = 0;i<3;i++){
                curr+='a'+i;
                recurse(curr,res,n-1);
                curr.pop_back();
            }
        }
        else{
            char last = curr.back();
            for(auto x: ump[last]){
                curr+=x;
                recurse(curr,res,n-1);
                curr.pop_back();
            }
        }
    }

};