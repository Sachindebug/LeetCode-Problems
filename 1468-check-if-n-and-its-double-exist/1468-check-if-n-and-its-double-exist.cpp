class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> ump;
        for(auto x:arr){
            if((x%2==0 && ump.find(x/2)!=ump.end()) || ump.find(x*2)!=ump.end()) return true;
            ump[x]++;
        }
        return false;
    }
};