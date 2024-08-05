class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> ump;
        int count = 0;
        for(auto x:arr) ump[x]++;
        for(auto x:arr){
            if(ump[x]==1) count++;
            if(count==k) return x;
        }
        return "";
    }
};