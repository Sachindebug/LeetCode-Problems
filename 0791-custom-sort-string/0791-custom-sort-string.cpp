class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> ump;
        for(int i=0;i<order.length();i++)
        {
            ump[order[i]]=i;
        }
        vector<pair<char,int>> arr;
        for(auto x:s)
        {
            arr.push_back({x,ump[x]});
        }
        sort(arr.begin(),arr.end(),[](pair<int,int> a,pair<int,int> b){
            if(a.second<b.second) return true;
            return false;
        });
        string res="";
        for(auto x:arr) res+=x.first;
        return res;
    }
};