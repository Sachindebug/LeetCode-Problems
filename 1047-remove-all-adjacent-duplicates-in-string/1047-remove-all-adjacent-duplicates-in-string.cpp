class Solution {
public:
    string removeDuplicates(string s) {
        string res="";
        for(auto x:s)
        {
            if(res.length()==0) res.push_back(x);
            else if(res.back()==x) res.pop_back();
            else res.push_back(x);
        }
        return res;
    }
};